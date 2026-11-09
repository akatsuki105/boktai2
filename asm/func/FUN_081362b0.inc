	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	movs r2, #0
	movs r3, #0
	ldr r0, _081362F0 @ =0x00000B3A
	adds r1, r4, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	cmp r3, r0
	bge _0813631E
	movs r6, #5
	mov ip, r6
	mov r8, r1
	adds r1, r4, #0
	movs r5, #0
	movs r7, #0x90
	lsls r7, r7, #1
	mov sb, r7
_081362DA:
	adds r0, r5, r4
	ldr r6, _081362F4 @ =0x00000755
	adds r0, r0, r6
	ldrb r0, [r0]
	mov r7, ip
	ands r0, r7
	cmp r0, #0
	beq _081362F8
	movs r0, #1
	b _081362FA
	.align 2, 0
_081362F0: .4byte 0x00000B3A
_081362F4: .4byte 0x00000755
_081362F8:
	movs r0, #0
_081362FA:
	cmp r0, #0
	bne _0813630E
	movs r6, #0xe9
	lsls r6, r6, #3
	adds r0, r1, r6
	strh r2, [r0]
	adds r2, #1
	cmp r2, #3
	ble _0813630E
	movs r2, #0
_0813630E:
	add r1, sb
	add r5, sb
	adds r3, #1
	mov r7, r8
	movs r6, #0
	ldrsh r0, [r7, r6]
	cmp r3, r0
	blt _081362DA
_0813631E:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
