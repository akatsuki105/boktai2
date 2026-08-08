	mov ip, sp
	push {r4, r5, r6, r7, r8, fp, ip, lr, pc}
	ldr r3, _0823025C @ =0x03002CF0
	sub sp, sp, #8
	ldr r2, [r3]
	sub fp, ip, #4
	tst r2, #1
	mov r5, #0x400
	movne r5, #0x200
	add r5, r5, #1
	ldr r3, _08230260 @ =0x03003530
	ldr r1, _08230264 @ =0x03003568
	ldr r2, [r3]
	ldr r4, [r1, r2, lsl #2]
	cmp r4, #0
	beq _082302E4
	ldr r8, _08230268 @ =0x030047C8
_08230178:
	ldr r3, [r4, #8]
	tst r3, r5
	mov r6, r3
	bne _082302D8
	tst r6, #0x10
	bne _0823026C
	sub r0, fp, #0x28
	add ip, r4, #0x20
	ldrh r3, [r4, #0x20]
	mov r7, r0
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
	ldrh r2, [r8]
	rsb r3, r2, r3
	add r3, r3, #0x78
	strh r3, [r0]
	ldrh r2, [r8, #2]
	rsb r3, r1, ip
	rsb r3, r2, r3
	add r3, r3, #0x5a
	strh r3, [r0, #2]
	ldrh r2, [r8, #4]
	add r3, ip, r1
	rsb r3, r2, r3
	strh r3, [r0, #4]
	ldrsh lr, [r7, #4]
	ldrsh r0, [fp, #-0x28]
	ldrh r2, [r4, #0x28]
	ldrsh r1, [r7, #2]
	b _0823027C
	.align 2, 0
_0823025C: .4byte 0x03002CF0
_08230260: .4byte 0x03003530
_08230264: .4byte 0x03003568
_08230268: .4byte 0x030047C8
_0823026C:
	ldrsh lr, [r4, #0x24]
	ldrsh r0, [r4, #0x20]
	ldrh r2, [r4, #0x28]
	ldrsh r1, [r4, #0x22]
_0823027C:
	ldrh r3, [r4, #0x2a]
	add ip, r0, r2
	add r2, r1, r3
	tst r6, #0x40
	beq _082302C8
	ldrsh r3, [r4, #0x30]
	cmn ip, r3
	bmi _082302D8
	ldrsh r3, [r4, #0x32]
	cmn r2, r3
	bmi _082302D8
	ldrsh r3, [r4, #0x2c]
	add r3, ip, r3
	cmp r3, #0xf0
	bgt _082302D8
	ldrsh r3, [r4, #0x2e]
	add r3, r2, r3
	cmp r3, #0xb4
	bgt _082302D8
_082302C8:
	mov r0, r4
	mov r1, ip
	mov r3, lr
	bl FUN_0822f6fc
_082302D8:
	ldr r4, [r4, #0x5c]
	cmp r4, #0
	bne _08230178
_082302E4:
	ldmdb fp, {r4, r5, r6, r7, r8, fp, sp, pc}
