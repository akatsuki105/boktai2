	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x18
	movs r0, #1
	strb r0, [r4, #0xa]
	movs r6, #0
	ldr r0, _08048410 @ =TextBox_StateIdle
	mov r8, r0
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r5, r1, r0
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r7, r1, r0
_080483EA:
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _08048420
	movs r0, #0
	strb r0, [r4, #8]
	adds r0, r4, #0
	bl TextRenderer_Advance
	cmp r0, #0
	beq _08048420
	movs r0, #1
	str r0, [r7]
	ldrb r0, [r4, #0xf]
	cmp r0, #0
	beq _08048414
	mov r0, r8
	str r0, [r5]
	b _08048426
	.align 2, 0
_08048410: .4byte TextBox_StateIdle
_08048414:
	ldr r0, _0804841C @ =TextBox_StateDone
	str r0, [r5]
	b _08048426
	.align 2, 0
_0804841C: .4byte TextBox_StateDone
_08048420:
	adds r6, #1
	cmp r6, #3
	ble _080483EA
_08048426:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
