	mov ip, sp
	push {r4, r5, fp, ip, lr, pc}
	ldr r3, _082303BC @ =0x03002CF0
	ldr r2, [r3]
	sub fp, ip, #4
	tst r2, #1
	mov r5, #0x400
	movne r5, #0x200
	add r5, r5, #1
	ldr r3, _082303C0 @ =0x03003530
	ldr r1, _082303C4 @ =0x03003568
	ldr r2, [r3]
	ldr r4, [r1, r2, lsl #2]
	cmp r4, #0
	ldmdbeq fp, {r4, r5, fp, sp, pc}
_08230324:
	ldr r2, [r4, #8]
	tst r2, r5
	bne _082303AC
	ldrh r3, [r4, #0x20]
	ldrh r1, [r4, #0x28]
	tst r2, #0x40
	ldrh r2, [r4, #0x22]
	ldrsh lr, [r4, #0x24]
	add r3, r3, r1
	lsl r3, r3, #0x10
	ldrh r1, [r4, #0x2a]
	asr ip, r3, #0x10
	add r2, r2, r1
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	bne _0823039C
	ldrsh r3, [r4, #0x30]
	cmn ip, r3
	bmi _082303AC
	ldrsh r3, [r4, #0x32]
	cmn r2, r3
	bmi _082303AC
	ldrsh r3, [r4, #0x2c]
	add r3, ip, r3
	cmp r3, #0xf0
	bgt _082303AC
	ldrsh r3, [r4, #0x2e]
	add r3, r2, r3
	cmp r3, #0xb4
	bgt _082303AC
_0823039C:
	mov r0, r4
	mov r1, ip
	mov r3, lr
	bl FUN_0822f6fc
_082303AC:
	ldr r4, [r4, #0x5c]
	cmp r4, #0
	bne _08230324
	ldmdb fp, {r4, r5, fp, sp, pc}
	.align 2, 0
_082303BC: .4byte 0x03002CF0
_082303C0: .4byte 0x03003530
_082303C4: .4byte 0x03003568
