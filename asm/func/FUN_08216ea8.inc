	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r0, _08216ED4 @ =0x0000166C
	adds r0, r0, r4
	mov ip, r0
	movs r7, #0
	ldr r2, _08216ED8 @ =0x00001FDC
	adds r1, r4, r2
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r2, #0x18
	adds r5, r4, r2
	adds r2, r5, r0
	movs r3, #0
	ldrsb r3, [r2, r3]
	cmp r3, #0x41
	bne _08216EEA
	ldrh r2, [r1]
	cmp r0, #0
	bne _08216EDC
	movs r7, #1
	b _08216EEE
	.align 2, 0
_08216ED4: .4byte 0x0000166C
_08216ED8: .4byte 0x00001FDC
_08216EDC:
	subs r0, r2, #1
	strh r0, [r1]
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, r5, r0
	strb r3, [r0]
	b _08216EEE
_08216EEA:
	movs r0, #0x41
	strb r0, [r2]
_08216EEE:
	movs r0, #0x97
	lsls r0, r0, #4
	add r0, ip
	movs r6, #0
	ldrsh r1, [r0, r6]
	adds r0, r4, #0
	bl FUN_08216dd8
	adds r0, r4, #0
	bl FUN_08216bdc
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
