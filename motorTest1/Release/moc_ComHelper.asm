; Listing generated by Microsoft (R) Optimizing Compiler Version 19.00.24215.1 

	TITLE	E:\finalUI_316latest_canuse_300ms_DB_moreliandong\motorTest1\GeneratedFiles\Release\moc_ComHelper.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRT
INCLUDELIB OLDNAMES

EXTRN	__imp_?staticMetaObject@QObject@@2UQMetaObject@@B:BYTE
CONST	SEGMENT
?qt_meta_stringdata_ComHelper@@3Uqt_meta_stringdata_ComHelper_t@@B DD 0ffffffffH ; qt_meta_stringdata_ComHelper
	DD	09H
	DD	00H
	DD	010H
	DB	'ComHelper', 00H
	ORG $+2
?qt_meta_data_ComHelper@@3QBIB DD 08H			; qt_meta_data_ComHelper
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
CONST	ENDS
PUBLIC	?metaObject@ComHelper@@UBEPBUQMetaObject@@XZ	; ComHelper::metaObject
PUBLIC	?qt_metacast@ComHelper@@UAEPAXPBD@Z		; ComHelper::qt_metacast
PUBLIC	?qt_metacall@ComHelper@@UAEHW4Call@QMetaObject@@HPAPAX@Z ; ComHelper::qt_metacall
PUBLIC	?qt_static_metacall@ComHelper@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z ; ComHelper::qt_static_metacall
PUBLIC	?staticMetaObject@ComHelper@@2UQMetaObject@@B	; ComHelper::staticMetaObject
EXTRN	__imp_?dynamicMetaObject@QObjectData@@QBEPAUQMetaObject@@XZ:PROC
EXTRN	__imp_?qt_metacast@QObject@@UAEPAXPBD@Z:PROC
EXTRN	__imp_?qt_metacall@QObject@@UAEHW4Call@QMetaObject@@HPAPAX@Z:PROC
CRT$XCU	SEGMENT
??staticMetaObject$initializer$@ComHelper@@2P6AXXZA@@3P6AXXZA DD FLAT:??__E?staticMetaObject@ComHelper@@2UQMetaObject@@B@@YAXXZ ; ??staticMetaObject$initializer$@ComHelper@@2P6AXXZA@@3P6AXXZA
CRT$XCU	ENDS
_DATA	SEGMENT
?staticMetaObject@ComHelper@@2UQMetaObject@@B DB 4 DUP(00H) ; ComHelper::staticMetaObject
	DD	FLAT:?qt_meta_stringdata_ComHelper@@3Uqt_meta_stringdata_ComHelper_t@@B
	DD	FLAT:?qt_meta_data_ComHelper@@3QBIB
	DD	FLAT:?qt_static_metacall@ComHelper@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z
	DD	00H
	DD	00H
_DATA	ENDS
; Function compile flags: /Ogtp
;	COMDAT ??__E?staticMetaObject@ComHelper@@2UQMetaObject@@B@@YAXXZ
text$di	SEGMENT
??__E?staticMetaObject@ComHelper@@2UQMetaObject@@B@@YAXXZ PROC ; `dynamic initializer for 'ComHelper::staticMetaObject'', COMDAT
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_comhelper.cpp
; Line 66
	mov	eax, DWORD PTR __imp_?staticMetaObject@QObject@@2UQMetaObject@@B
	mov	DWORD PTR ?staticMetaObject@ComHelper@@2UQMetaObject@@B, eax
; Line 71
	ret	0
??__E?staticMetaObject@ComHelper@@2UQMetaObject@@B@@YAXXZ ENDP ; `dynamic initializer for 'ComHelper::staticMetaObject''
text$di	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?qt_static_metacall@ComHelper@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z
_TEXT	SEGMENT
__o$ = 8						; size = 4
__c$ = 12						; size = 4
__id$ = 16						; size = 4
__a$ = 20						; size = 4
?qt_static_metacall@ComHelper@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z PROC ; ComHelper::qt_static_metacall, COMDAT
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_comhelper.cpp
; Line 63
	ret	0
?qt_static_metacall@ComHelper@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z ENDP ; ComHelper::qt_static_metacall
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?qt_metacall@ComHelper@@UAEHW4Call@QMetaObject@@HPAPAX@Z
_TEXT	SEGMENT
__c$ = 8						; size = 4
__id$ = 12						; size = 4
__a$ = 16						; size = 4
?qt_metacall@ComHelper@@UAEHW4Call@QMetaObject@@HPAPAX@Z PROC ; ComHelper::qt_metacall, COMDAT
; _this$ = ecx
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_comhelper.cpp
; Line 89
	push	ebp
	mov	ebp, esp
; Line 92
	pop	ebp
; Line 90
	jmp	DWORD PTR __imp_?qt_metacall@QObject@@UAEHW4Call@QMetaObject@@HPAPAX@Z
?qt_metacall@ComHelper@@UAEHW4Call@QMetaObject@@HPAPAX@Z ENDP ; ComHelper::qt_metacall
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?qt_metacast@ComHelper@@UAEPAXPBD@Z
_TEXT	SEGMENT
__clname$ = 8						; size = 4
?qt_metacast@ComHelper@@UAEPAXPBD@Z PROC		; ComHelper::qt_metacast, COMDAT
; _this$ = ecx
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_comhelper.cpp
; Line 81
	push	ebp
	mov	ebp, esp
	push	esi
; Line 82
	mov	esi, DWORD PTR __clname$[ebp]
	push	edi
	mov	edi, ecx
	test	esi, esi
	jne	SHORT $LN2@qt_metacas
	pop	edi
	xor	eax, eax
	pop	esi
; Line 86
	pop	ebp
	ret	4
$LN2@qt_metacas:
; Line 83
	mov	eax, OFFSET ?qt_meta_stringdata_ComHelper@@3Uqt_meta_stringdata_ComHelper_t@@B+16
	mov	ecx, esi
	npad	3
$LL5@qt_metacas:
	mov	dl, BYTE PTR [ecx]
	cmp	dl, BYTE PTR [eax]
	jne	SHORT $LN6@qt_metacas
	test	dl, dl
	je	SHORT $LN7@qt_metacas
	mov	dl, BYTE PTR [ecx+1]
	cmp	dl, BYTE PTR [eax+1]
	jne	SHORT $LN6@qt_metacas
	add	ecx, 2
	add	eax, 2
	test	dl, dl
	jne	SHORT $LL5@qt_metacas
$LN7@qt_metacas:
	xor	eax, eax
	jmp	SHORT $LN8@qt_metacas
$LN6@qt_metacas:
	sbb	eax, eax
	or	eax, 1
$LN8@qt_metacas:
	test	eax, eax
	jne	SHORT $LN3@qt_metacas
; Line 84
	mov	eax, edi
	pop	edi
	pop	esi
; Line 86
	pop	ebp
	ret	4
$LN3@qt_metacas:
; Line 85
	push	esi
	mov	ecx, edi
	call	DWORD PTR __imp_?qt_metacast@QObject@@UAEPAXPBD@Z
	pop	edi
	pop	esi
; Line 86
	pop	ebp
	ret	4
?qt_metacast@ComHelper@@UAEPAXPBD@Z ENDP		; ComHelper::qt_metacast
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?metaObject@ComHelper@@UBEPBUQMetaObject@@XZ
_TEXT	SEGMENT
?metaObject@ComHelper@@UBEPBUQMetaObject@@XZ PROC	; ComHelper::metaObject, COMDAT
; _this$ = ecx
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_comhelper.cpp
; Line 77
	mov	ecx, DWORD PTR [ecx+4]
	cmp	DWORD PTR [ecx+24], 0
	je	SHORT $LN3@metaObject
	jmp	DWORD PTR __imp_?dynamicMetaObject@QObjectData@@QBEPAUQMetaObject@@XZ
$LN3@metaObject:
	mov	eax, OFFSET ?staticMetaObject@ComHelper@@2UQMetaObject@@B ; ComHelper::staticMetaObject
; Line 78
	ret	0
?metaObject@ComHelper@@UBEPBUQMetaObject@@XZ ENDP	; ComHelper::metaObject
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ??C?$QScopedPointer@VQObjectData@@U?$QScopedPointerDeleter@VQObjectData@@@@@@QBEPAVQObjectData@@XZ
_TEXT	SEGMENT
??C?$QScopedPointer@VQObjectData@@U?$QScopedPointerDeleter@VQObjectData@@@@@@QBEPAVQObjectData@@XZ PROC ; QScopedPointer<QObjectData,QScopedPointerDeleter<QObjectData> >::operator->, COMDAT
; _this$ = ecx
; File d:\qtlatest\5.12.0\msvc2017\include\qtcore\qscopedpointer.h
; Line 118
	mov	eax, DWORD PTR [ecx]
; Line 119
	ret	0
??C?$QScopedPointer@VQObjectData@@U?$QScopedPointerDeleter@VQObjectData@@@@@@QBEPAVQObjectData@@XZ ENDP ; QScopedPointer<QObjectData,QScopedPointerDeleter<QObjectData> >::operator->
_TEXT	ENDS
END
