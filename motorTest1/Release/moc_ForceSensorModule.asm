; Listing generated by Microsoft (R) Optimizing Compiler Version 19.00.24215.1 

	TITLE	E:\finalUI_316latest_canuse_300ms_DB_moreliandong\motorTest1\GeneratedFiles\Release\moc_ForceSensorModule.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB MSVCRT
INCLUDELIB OLDNAMES

EXTRN	__imp_?staticMetaObject@QObject@@2UQMetaObject@@B:BYTE
CONST	SEGMENT
?qt_meta_stringdata_ForceSensorModule@@3Uqt_meta_stringdata_ForceSensorModule_t@@B DD 0ffffffffH ; qt_meta_stringdata_ForceSensorModule
	DD	011H
	DD	00H
	DD	030H
	DD	0ffffffffH
	DD	014H
	DD	00H
	DD	032H
	DD	0ffffffffH
	DD	00H
	DD	00H
	DD	037H
	DB	'ForceSensorModule', 00H, 'OnforceSensorReadTmr', 00H, 00H
?qt_meta_data_ForceSensorModule@@3QBIB DD 08H		; qt_meta_data_ForceSensorModule
	DD	00H
	DD	00H
	DD	00H
	DD	01H
	DD	0eH
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	00H
	DD	01H
	DD	00H
	DD	013H
	DD	02H
	DD	08H
	DD	02bH
	DD	00H
CONST	ENDS
PUBLIC	?metaObject@ForceSensorModule@@UBEPBUQMetaObject@@XZ ; ForceSensorModule::metaObject
PUBLIC	?qt_metacast@ForceSensorModule@@UAEPAXPBD@Z	; ForceSensorModule::qt_metacast
PUBLIC	?qt_metacall@ForceSensorModule@@UAEHW4Call@QMetaObject@@HPAPAX@Z ; ForceSensorModule::qt_metacall
PUBLIC	?qt_static_metacall@ForceSensorModule@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z ; ForceSensorModule::qt_static_metacall
PUBLIC	?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B ; ForceSensorModule::staticMetaObject
EXTRN	__imp_?dynamicMetaObject@QObjectData@@QBEPAUQMetaObject@@XZ:PROC
EXTRN	__imp_?qt_metacast@QObject@@UAEPAXPBD@Z:PROC
EXTRN	__imp_?qt_metacall@QObject@@UAEHW4Call@QMetaObject@@HPAPAX@Z:PROC
EXTRN	?OnforceSensorReadTmr@ForceSensorModule@@AAEXXZ:PROC ; ForceSensorModule::OnforceSensorReadTmr
CRT$XCU	SEGMENT
??staticMetaObject$initializer$@ForceSensorModule@@2P6AXXZA@@3P6AXXZA DD FLAT:??__E?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B@@YAXXZ ; ??staticMetaObject$initializer$@ForceSensorModule@@2P6AXXZA@@3P6AXXZA
CRT$XCU	ENDS
_DATA	SEGMENT
?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B DB 4 DUP(00H) ; ForceSensorModule::staticMetaObject
	DD	FLAT:?qt_meta_stringdata_ForceSensorModule@@3Uqt_meta_stringdata_ForceSensorModule_t@@B
	DD	FLAT:?qt_meta_data_ForceSensorModule@@3QBIB
	DD	FLAT:?qt_static_metacall@ForceSensorModule@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z
	DD	00H
	DD	00H
_DATA	ENDS
; Function compile flags: /Ogtp
;	COMDAT ??__E?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B@@YAXXZ
text$di	SEGMENT
??__E?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B@@YAXXZ PROC ; `dynamic initializer for 'ForceSensorModule::staticMetaObject'', COMDAT
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_forcesensormodule.cpp
; Line 80
	mov	eax, DWORD PTR __imp_?staticMetaObject@QObject@@2UQMetaObject@@B
	mov	DWORD PTR ?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B, eax
; Line 85
	ret	0
??__E?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B@@YAXXZ ENDP ; `dynamic initializer for 'ForceSensorModule::staticMetaObject''
text$di	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?qt_static_metacall@ForceSensorModule@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z
_TEXT	SEGMENT
__o$ = 8						; size = 4
__c$ = 12						; size = 4
__id$ = 16						; size = 4
__a$ = 20						; size = 4
?qt_static_metacall@ForceSensorModule@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z PROC ; ForceSensorModule::qt_static_metacall, COMDAT
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_forcesensormodule.cpp
; Line 67
	push	ebp
	mov	ebp, esp
; Line 68
	cmp	DWORD PTR __c$[ebp], 0
	jne	SHORT $LN6@qt_static_
; Line 71
	cmp	DWORD PTR __id$[ebp], 0
	jne	SHORT $LN6@qt_static_
; Line 72
	mov	ecx, DWORD PTR __o$[ebp]
; Line 77
	pop	ebp
; Line 72
	jmp	?OnforceSensorReadTmr@ForceSensorModule@@AAEXXZ ; ForceSensorModule::OnforceSensorReadTmr
$LN6@qt_static_:
; Line 77
	pop	ebp
	ret	0
?qt_static_metacall@ForceSensorModule@@CAXPAVQObject@@W4Call@QMetaObject@@HPAPAX@Z ENDP ; ForceSensorModule::qt_static_metacall
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?qt_metacall@ForceSensorModule@@UAEHW4Call@QMetaObject@@HPAPAX@Z
_TEXT	SEGMENT
__c$ = 8						; size = 4
__id$ = 12						; size = 4
__a$ = 16						; size = 4
?qt_metacall@ForceSensorModule@@UAEHW4Call@QMetaObject@@HPAPAX@Z PROC ; ForceSensorModule::qt_metacall, COMDAT
; _this$ = ecx
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_forcesensormodule.cpp
; Line 103
	push	ebp
	mov	ebp, esp
	push	ebx
	push	esi
	push	edi
; Line 104
	push	DWORD PTR __a$[ebp]
	mov	edi, DWORD PTR __c$[ebp]
	mov	ebx, ecx
	push	DWORD PTR __id$[ebp]
	push	edi
	call	DWORD PTR __imp_?qt_metacall@QObject@@UAEHW4Call@QMetaObject@@HPAPAX@Z
	mov	esi, eax
; Line 105
	test	esi, esi
	js	SHORT $LN1@qt_metacal
; Line 107
	test	edi, edi
	jne	SHORT $LN3@qt_metacal
; Line 108
	cmp	esi, 1
	jge	SHORT $LN7@qt_metacal
; Line 109
	test	esi, esi
	jne	SHORT $LN7@qt_metacal
	mov	ecx, ebx
	call	?OnforceSensorReadTmr@ForceSensorModule@@AAEXXZ ; ForceSensorModule::OnforceSensorReadTmr
; Line 114
	dec	esi
	pop	edi
; Line 116
	mov	eax, esi
	pop	esi
	pop	ebx
; Line 117
	pop	ebp
	ret	12					; 0000000cH
$LN3@qt_metacal:
; Line 111
	cmp	edi, 12					; 0000000cH
	jne	SHORT $LN6@qt_metacal
; Line 112
	cmp	esi, 1
	jge	SHORT $LN7@qt_metacal
; Line 113
	mov	eax, DWORD PTR __a$[ebp]
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [eax], -1
$LN7@qt_metacal:
; Line 114
	dec	esi
$LN6@qt_metacal:
; Line 116
	mov	eax, esi
$LN1@qt_metacal:
	pop	edi
	pop	esi
	pop	ebx
; Line 117
	pop	ebp
	ret	12					; 0000000cH
?qt_metacall@ForceSensorModule@@UAEHW4Call@QMetaObject@@HPAPAX@Z ENDP ; ForceSensorModule::qt_metacall
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?qt_metacast@ForceSensorModule@@UAEPAXPBD@Z
_TEXT	SEGMENT
__clname$ = 8						; size = 4
?qt_metacast@ForceSensorModule@@UAEPAXPBD@Z PROC	; ForceSensorModule::qt_metacast, COMDAT
; _this$ = ecx
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_forcesensormodule.cpp
; Line 95
	push	ebp
	mov	ebp, esp
	push	esi
; Line 96
	mov	esi, DWORD PTR __clname$[ebp]
	push	edi
	mov	edi, ecx
	test	esi, esi
	jne	SHORT $LN2@qt_metacas
	pop	edi
	xor	eax, eax
	pop	esi
; Line 100
	pop	ebp
	ret	4
$LN2@qt_metacas:
; Line 97
	mov	eax, OFFSET ?qt_meta_stringdata_ForceSensorModule@@3Uqt_meta_stringdata_ForceSensorModule_t@@B+48
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
; Line 98
	mov	eax, edi
	pop	edi
	pop	esi
; Line 100
	pop	ebp
	ret	4
$LN3@qt_metacas:
; Line 99
	push	esi
	mov	ecx, edi
	call	DWORD PTR __imp_?qt_metacast@QObject@@UAEPAXPBD@Z
	pop	edi
	pop	esi
; Line 100
	pop	ebp
	ret	4
?qt_metacast@ForceSensorModule@@UAEPAXPBD@Z ENDP	; ForceSensorModule::qt_metacast
_TEXT	ENDS
; Function compile flags: /Ogtp
;	COMDAT ?metaObject@ForceSensorModule@@UBEPBUQMetaObject@@XZ
_TEXT	SEGMENT
?metaObject@ForceSensorModule@@UBEPBUQMetaObject@@XZ PROC ; ForceSensorModule::metaObject, COMDAT
; _this$ = ecx
; File e:\finalui_316latest_canuse_300ms_db_moreliandong\motortest1\generatedfiles\release\moc_forcesensormodule.cpp
; Line 91
	mov	ecx, DWORD PTR [ecx+4]
	cmp	DWORD PTR [ecx+24], 0
	je	SHORT $LN3@metaObject
	jmp	DWORD PTR __imp_?dynamicMetaObject@QObjectData@@QBEPAUQMetaObject@@XZ
$LN3@metaObject:
	mov	eax, OFFSET ?staticMetaObject@ForceSensorModule@@2UQMetaObject@@B ; ForceSensorModule::staticMetaObject
; Line 92
	ret	0
?metaObject@ForceSensorModule@@UBEPBUQMetaObject@@XZ ENDP ; ForceSensorModule::metaObject
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
