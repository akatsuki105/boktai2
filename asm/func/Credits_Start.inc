	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r4, #0
	strb r4, [r5, #0x18]
	strb r4, [r5, #0x19]
	str r4, [r5, #0x20]
	movs r0, #0x70
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r5, #0x1a]
	str r4, [r5, #0x1c]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804A882
	bl FUN_0823d340
	str r0, [r5, #0x28]
	cmp r0, #0
	bne _0804A88E
_0804A882:
	movs r0, #1
	rsbs r0, r0, #0
	b _0804A978
_0804A888:
	subs r0, r7, #1
	strb r0, [r5, #0x1b]
	b _0804A924
_0804A88E:
	movs r0, #0x74
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0804A924
	bl FUN_0823d34c
	str r0, [r5, #0x2c]
	bl VM_SetPC
	movs r7, #0
	movs r0, #1
	rsbs r0, r0, #0
	mov sb, r0
	adds r6, r5, #0
	adds r6, #0x34
	movs r1, #0xb4
	adds r1, r1, r5
	mov r8, r1
_0804A8B4:
	bl VM_GetValue
	lsls r4, r7, #1
	strh r0, [r6]
	bl VM_GetValue
	movs r2, #0xda
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0x8d
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0xad
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0xcd
	lsls r2, r2, #2
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	bl VM_GetValue
	mov r1, r8
	strh r0, [r1]
	bl VM_GetValue
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r1, r5, r2
	adds r1, r1, r4
	strh r0, [r1]
	ldrb r0, [r5, #0x1a]
	cmp r7, r0
	blt _0804A918
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, sb
	beq _0804A888
_0804A918:
	adds r6, #2
	movs r2, #2
	add r8, r2
	adds r7, #1
	cmp r7, #0x3f
	ble _0804A8B4
_0804A924:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r5, #0x30]
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x32]
	ldr r0, [r5, #0x28]
	bl TextBox_Start
	movs r0, #1
	bl TextBox_SetInstant
	ldr r0, _0804A984 @ =0x0000539C
	bl TextBox_SetBgPltt
	ldrb r0, [r5, #0x1a]
	bl TextBox_ShowLine
	adds r0, r5, #0
	bl Credits_ApplyLineRect
	ldr r1, _0804A988 @ =0x03004494
	ldr r2, _0804A98C @ =0x00001084
	adds r0, r2, #0
	strh r0, [r1]
	ldr r1, _0804A990 @ =0x03004454
	movs r2, #0x80
	lsls r2, r2, #8
	adds r0, r2, #0
	strh r0, [r1]
	ldr r0, _0804A994 @ =0x03004040
	str r4, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl Credits_SetStep
	movs r0, #0
_0804A978:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804A984: .4byte 0x0000539C
_0804A988: .4byte 0x03004494
_0804A98C: .4byte 0x00001084
_0804A990: .4byte 0x03004454
_0804A994: .4byte 0x03004040
