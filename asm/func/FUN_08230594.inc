	mov ip, sp
	push {r4, r5, r6, r7, fp, ip, lr, pc}
	ldr r3, _082306C0 @ =0x03002CF0
	sub sp, sp, #8
	ldr r2, [r3]
	sub fp, ip, #4
	tst r2, #1
	mov r5, #0x400
	movne r5, #0x200
	add r5, r5, #1
	ldr r3, _082306C4 @ =0x03003530
	ldr r1, _082306C8 @ =0x03003568
	ldr r2, [r3]
	ldr r4, [r1, r2, lsl #2]
	cmp r4, #0
	beq _08230718
	ldr r7, _082306CC @ =0x030047C8
_082305D8:
	ldr r3, [r4, #8]
	tst r3, r5
	bne _0823070C
	tst r3, #0x2000
	beq _0823070C
	tst r3, #0x10
	bne _082306D0
	sub r0, fp, #0x24
	add ip, r4, #0x20
	ldrh r3, [r4, #0x20]
	mov r6, r0
	ldrh r2, [ip, #4]
	lsl r3, r3, #0x10
	asr r1, r3, #0x11
	lsl r2, r2, #0x10
	asr r2, r2, #0x11
	rsb r3, r2, r1
	add r3, r3, r3, lsl #1
	lsls r3, r3, #4
	asrpl r3, r3, #8
	rsbmi r3, r3, #0
	asrmi r3, r3, #8
	rsbmi r3, r3, #0
	strh r3, [r0]
	add r3, r1, r2
	add r3, r3, r3, lsl #1
	lsls r3, r3, #4
	asrpl r2, r3, #8
	rsbmi r3, r3, #0
	asrmi r3, r3, #8
	rsbmi r2, r3, #0
	ldrsh r3, [ip, #2]
	mov ip, r2
	add r3, r3, r3, lsl #1
	lsls r3, r3, #3
	asrpl r1, r3, #8
	rsbmi r3, r3, #0
	asrmi r3, r3, #8
	rsbmi r1, r3, #0
	ldrh r3, [r0]
	ldrh r2, [r7]
	rsb r3, r2, r3
	add r3, r3, #0x78
	strh r3, [r0]
	ldrh r2, [r7, #2]
	rsb r3, r1, ip
	rsb r3, r2, r3
	add r3, r3, #0x5a
	strh r3, [r0, #2]
	ldrh r2, [r7, #4]
	add r3, ip, r1
	rsb r3, r2, r3
	strh r3, [r0, #4]
	ldrh r2, [fp, #-0x24]
	ldrh r1, [r4, #0x28]
	ldrsh lr, [r6, #4]
	ldrh r3, [r6, #2]
	b _082306E0
	.align 2, 0
_082306C0: .4byte 0x03002CF0
_082306C4: .4byte 0x03003530
_082306C8: .4byte 0x03003568
_082306CC: .4byte 0x030047C8
_082306D0:
	ldrh r2, [r4, #0x20]
	ldrh r1, [r4, #0x28]
	ldrsh lr, [r4, #0x24]
	ldrh r3, [r4, #0x22]
_082306E0:
	add r2, r2, r1
	lsl r2, r2, #0x10
	ldrh r1, [r4, #0x2a]
	asr ip, r2, #0x10
	add r3, r3, r1
	lsl r3, r3, #0x10
	asr r2, r3, #0x10
	mov r0, r4
	mov r1, ip
	mov r3, lr
	bl FUN_0822f6fc
_0823070C:
	ldr r4, [r4, #0x5c]
	cmp r4, #0
	bne _082305D8
_08230718:
	ldmdb fp, {r4, r5, r6, r7, fp, sp, pc}
