package com.acme.printerScheduler;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class PrinterScheduler {

	/*
	 * 테스트 케이스 입력 데이터를 읽어들여 저장하는 클래스
	 */
	static class TestCaseInput {
		// 출력 순서가 궁금한 대상 문서의 순번
		int targetDocSeq;
		// 개별 문서의 출력 우선 순위를 저장한 배열
		int[] docPriorityArr;

		/**
		 * 테스트 케이스 입력 데이터 클래스 생성자
		 * 
		 * @param docCount
		 *            문서 갯수
		 * @param targetDocSeq
		 *            출력 순서가 궁금한 대상 문서의 순번
		 */
		public TestCaseInput(int docCount, int targetDocSeq) {
			// 출력 우선 순위를 저장할 배열 초기화
			docPriorityArr = new int[docCount];
			// 출력 순서 탐색 대상 문서 순번 설정
			this.targetDocSeq = targetDocSeq;
		}

		/**
		 * 문서의 출력 우선 순위 설정
		 * 
		 * @param docIndex
		 *            출력 요청 순번
		 * @param priority
		 *            우선 순위
		 */
		public void setDocPriority(int docIndex, int priority) {
			docPriorityArr[docIndex] = priority;
		}

		/**
		 * 문서의 출력 우선 순위 반환
		 * 
		 * @param docIndex
		 *            출력 요청 순번
		 * @return 우선순위
		 */
		public int getDocPriority(int docIndex) {
			return docPriorityArr[docIndex];
		}

		/**
		 * 테스트 케이스에 포함된 문서 갯수 반환
		 * 
		 * @return
		 */
		public int getDocumentCount() {
			return docPriorityArr.length;
		}

		/**
		 * 출력 순서를 알고자 하는 문서의 순서 반환
		 * 
		 * @return
		 */
		public int getTargetDocSeq() {
			return targetDocSeq;
		}
	}

	/**
	 * 문서 출력 요청 정보를 저장하는 클래스
	 */
	static class DocPrintRequest {
		// 문서 출력 요청 순번
		private int printRequestSeq;
		// 출력 우선 순위
		private int priority;

		public DocPrintRequest(int printRequestSeq, int priority) {
			this.printRequestSeq = printRequestSeq;
			this.priority = priority;
		}

		public int getPrintRequestSeq() {
			return printRequestSeq;
		}

		public int getPriority() {
			return priority;
		}
	}

	/**
	 * 테스트 케이스의 문서 출력 순서를 저장하는 클래스
	 *
	 */
	static class DocPrintSequence {
		// 프뢴터로 출력되는 문서의 순번을 저장하는 배열
		private int[] printSeqArray;

		/*
		 * 문서 출력 순서를 저장하는 클래스의 생성자
		 * 
		 * @param 테스트 케이스의 문서 갯수
		 */
		public DocPrintSequence(int docCount) {
			printSeqArray = new int[docCount];
		}

		/**
		 * 출력되는 문서의 순번 설정
		 * 
		 * @param docSeq
		 *            문서의 입력 순번
		 * @param printSeq
		 *            문서 출력 순서
		 */
		public void setPrintOrder(int docSeq, int printSeq) {
			printSeqArray[printSeq] = docSeq;
		}

		/**
		 * @throws Exception
		 */
		public int getPrintSequence(int docSeq) throws Exception {
			for (int idx = 0; idx < printSeqArray.length; idx++) {
				if (printSeqArray[idx] == docSeq) {
					return idx;
				}
			}
			throw new Exception("Cannot find document seq : " + docSeq);
		}
	}

	public static void main(String args[]) {

		// ## 1 단계 : 입력 데이터를 읽어 들인다. ##
		TestCaseInput testCaseInputArr[];
		// 실행 프로그램 인자가 없으면 콘솔에서 테스트 케이스 데이터를 입력 받는다.
		if (args.length == 0) {
			testCaseInputArr = readAllTestCase(System.in, "console");
		}
		// 실행 프로그램 인자가 존재하면, 첫번째 인자를 입력 파일 명칭으로 가정하고 텍스트 파일에서 입력 받는다.
		else {
			String inputFileName = args[0];
			InputStream inputStream = null;
			try {
				File inputFile = new File(inputFileName);
				inputStream = new FileInputStream(inputFile);
			} catch (FileNotFoundException e) {
				handleError("Cannot find file : " + inputFileName);
			}
			testCaseInputArr = readAllTestCase(inputStream, inputFileName);
		}
		// 입력된 테스트 케이스 개요를 출력한다.
		reportInputTestCases(testCaseInputArr);

		// ## 2 단계 : 인쇄 요청 큐(queue) 생성한 후 출력 순서를 스케줄링한 후, 검색 대상 문서의 출력 순서를 콘솔에 출력한다. ##
		try {
			for (int idx = 0; idx < testCaseInputArr.length; idx++) {
				DocPrintSequence docPrintOrder = schedulePrintOrder(testCaseInputArr[idx]);
				// 검색 대상 문서의 출력 순서를 프린트
				int targetDocPrintSeq = docPrintOrder.getPrintSequence(testCaseInputArr[idx].getTargetDocSeq());
				System.out.println(targetDocPrintSeq + 1);
			}
		} catch (Exception ex) {
			ex.printStackTrace();
			handleError(ex.getMessage());
		}
	}

	/**
	 * 문서 인쇄 요청 데이터 (요청 순번 + 우선순위)를 이용해 문서 출력 스케줄 계산
	 * 
	 * @param testCaseInput
	 * @return
	 */
	private static DocPrintSequence schedulePrintOrder(TestCaseInput testCaseInput) {
		// 문서 인쇄 요청을 순서대로 큐에 담는다.
		int docCount = testCaseInput.getDocumentCount();
		Queue<DocPrintRequest> reqQueue = new LinkedList<DocPrintRequest>();
		for (int idx = 0; idx < docCount; idx++) {
			int priority = testCaseInput.getDocPriority(idx);
			reqQueue.add(new DocPrintRequest(idx, priority));
		}

		// 우선 순위를 고려하여 출력 순서를 계산한다.
		DocPrintSequence docPrintSequence = new DocPrintSequence(docCount);

		int printSeq = 0;
		while (!reqQueue.isEmpty()) {
			// 큐에서 문서 출력 요청을 하나 꺼낸다.
			DocPrintRequest printRequest = reqQueue.poll();
			int currentDocPrioty = printRequest.getPriority();
			// 큐에 남은 문서가 있는지를 확인하고 없으면, 마지막 인쇄 요청 건의 출력 순서를 기록한다.
			if (reqQueue.isEmpty()) {
				docPrintSequence.setPrintOrder(printRequest.getPrintRequestSeq(), printSeq++);
			}
			else {
				// 큐에 남은 문서 중에 현재 문서보다 우선 순위가 높은 요청이 있는지 검사한다.
				boolean isUpperPriory = false;
				Iterator<DocPrintRequest> iter = reqQueue.iterator();
				while (iter.hasNext()) {
					DocPrintRequest remainRequest = iter.next();
					if (remainRequest.getPriority() > currentDocPrioty) {
						isUpperPriory = true;
					}
				}
				// 큐에 남은 문서의 우선 순위가 높은 것이 발견 되면, 현재 문서의 출력 요청을 다시 큐에 담아 둔다.
				if (isUpperPriory) {
					reqQueue.add(printRequest);
				} 
				// 보다 높은 우선 순위의 문서를 발견할 수 없다면, 출력 순서를 기록한다.
				else {
					docPrintSequence.setPrintOrder(printRequest.getPrintRequestSeq(), printSeq++);
				}
			}
		}

		return docPrintSequence;
	}

	/**
	 * 입력된 테스트 케이스의 개요를 출력한다.
	 * 
	 * @param testCaseInputArr
	 */
	private static void reportInputTestCases(TestCaseInput[] testCaseInputArr) {
		System.out.format("Input test case count : %d\n", testCaseInputArr.length);
		for (int idx = 0; idx < testCaseInputArr.length; idx++) {
			System.out.format("Document number for test case #%d is %d\n", idx,
					testCaseInputArr[idx].getDocumentCount());
		}
	}

	/**
	 * 테스트 케이스 데이터 입력
	 * 
	 * @param inputStream
	 *            입력 스트림
	 * @param inputFileName
	 *            입력 스트림 파일 명칭
	 * @return
	 */
	private static TestCaseInput[] readAllTestCase(InputStream inputStream, String inputFileName) {
		TestCaseInput testCaseInputArr[] = null;
		try {
			InputStreamReader isr = new InputStreamReader(inputStream);
			Scanner scanner = new Scanner(isr);

			// 테스트 케이스 갯수 입력 (최대 10건 입력)
			int testCaseCnt = inputNumber(scanner, true, 1, 10);

			// 개별 테스트 케이스 입력 (테스트 케이스 갯수 만큼 반복)
			testCaseInputArr = new TestCaseInput[testCaseCnt];
			for (int i = 0; i < testCaseCnt; i++) {
				testCaseInputArr[i] = readTestCase(scanner);
			}
		} catch (IOException ex) {
			handleError(ex.getMessage() + "\nError while read data from file : " + inputFileName);
		}

		return testCaseInputArr;
	}

	private static TestCaseInput readTestCase(Scanner scanner) {
		TestCaseInput testCaseInput = null;
		try {
			// 문서의 갯수와 대상 문서의 순번 입력
			int docCount = inputNumber(scanner, false, 1, 100);
			int targetDocSeq = inputNumber(scanner, true, 0, docCount - 1);

			// 테스트 케이스 입력 객체 생성
			testCaseInput = new TestCaseInput(docCount, targetDocSeq);
			// 문서 출력 우선 순위 입력
			for (int idx = 0; idx < docCount; idx++) {
				int priority = inputNumber(scanner, false, 1, 9);
				testCaseInput.setDocPriority(idx, priority);
			}
		} catch (IOException ex) {
			handleError(ex.getMessage());
		}
		return testCaseInput;
	}

	/**
	 * 입력 스캐너로부터 숫자를 입력 받아 반환한다.
	 * 
	 * @param scanner
	 *            입력 데이터 스캐너
	 * @param readLine
	 *            true 인 경우 readLine 메소드로 읽어들이고, 아니면 readInt 메소드로 읽어들인다.
	 * @param min
	 *            최소 값
	 * @param max
	 *            최대 값
	 * @throws IOException
	 */
	private static int inputNumber(Scanner scanner, boolean readLine, int min, int max) throws IOException {
		int intValue;
		if (readLine) {
			String inputStr = scanner.nextLine();
			intValue = Integer.parseInt(inputStr.trim());
		} else {
			intValue = scanner.nextInt();
		}

		validateInputValue(intValue, min, max);
		return intValue;
	}

	/**
	 * 입력된 정수 값의 범위 검사 (허용된 범위를 벗어난 경우, 오류 출력 후 프로그램 종료)
	 * 
	 * @param inputvalue
	 *            정수 입력 값
	 * @param min
	 *            최소 허용 값
	 * @param max
	 *            최대 허용 값
	 * @throws IOException
	 */
	private static void validateInputValue(int inputValue, int min, int max) throws IOException {
		if (inputValue < min) {
			throw new IOException(String.format("inputVaue(%d) is lower than min(%d)", inputValue, min));
		} else if (inputValue > max) {
			throw new IOException(String.format("inputVaue(%d) is greater than max(%d)", inputValue, max));
		}
	}

	/**
	 * 오류 메시지 출력 후 프로그램 종료
	 * 
	 * @param errorMessage
	 *            오류 메시지
	 */
	private static void handleError(String errorMessage) {
		System.out.println(errorMessage);
		System.exit(1);
	}

}
