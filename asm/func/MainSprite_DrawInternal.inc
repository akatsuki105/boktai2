	mov ip, sp
	push {r4, r5, r6, r7, r8, sb, sl, fp, ip, lr, pc}
	sub fp, ip, #4
	sub sp, sp, #0x2d4
	mov r5, #0
	str r5, [fp, #-0x2c4]
	str r5, [fp, #-0x2c8]
	str r0, [fp, #-0x2b0]
	str r1, [fp, #-0x2b4]
	cmp r3, #0
	str r3, [fp, #-0x2bc]
	ldr r3, [r0, #8]
	str r2, [fp, #-0x2b8]
	and ip, r3, #4
	str ip, [fp, #-0x2d8]
	and r3, r3, #8
	str r3, [fp, #-0x2dc]
	ldrge r0, [fp, #-0x2bc]
	asrge r3, r0, #1
	ldrlt r1, [fp, #-0x2bc]
	rsblt r3, r1, #0
	asrlt r3, r3, #1
	rsblt r3, r3, #0
	str r3, [fp, #-0x2bc]
	cmn r3, #0x80
	mvnlt r2, #0x7f
	strlt r2, [fp, #-0x2bc]
	blt _0822F77C
	ldr r3, [fp, #-0x2bc]
	cmp r3, #0x7f
	movge r3, #0x7f
	str r3, [fp, #-0x2bc]
_0822F77C:
	ldr r3, _0822F9F4 @ =0x030044B0
	ldr ip, [fp, #-0x2b0]
	ldrb r2, [r3]
	mov r5, #0
	str r5, [fp, #-0x2d4]
	ldr r5, [ip, #8]
	tst r2, #1
	beq _0822F7B0
	ldrb r3, [ip, #0x1a]
	cmp r3, #0
	beq _0822F7B0
	tst r5, #0x10000
	beq _0822F7B8
_0822F7B0:
	tst r5, #0x800
	beq _0822F7C4
_0822F7B8:
	ldr r0, [fp, #-0x2d4]
	orr r0, r0, #0x1000
	str r0, [fp, #-0x2d4]
_0822F7C4:
	ldr r3, _0822F9F8 @ =0x030044AC
	ldr r2, [r3]
	cmp r2, #0
	beq _0822F7E8
	ldr r1, [fp, #-0x2d4]
	tst r5, #0x4000
	orr r3, r1, #0x400
	movne r1, r3
	str r1, [fp, #-0x2d4]
_0822F7E8:
	ldr r2, [fp, #-0x2d4]
	tst r5, #0x100
	orr r3, r2, #0x800
	movne r2, r3
	str r2, [fp, #-0x2d4]
	ands r3, r5, #2
	streq r3, [fp, #-0x2d0]
	streq r3, [fp, #-0x2cc]
	beq _0822FA5C
	ldr r3, [fp, #-0x2b0]
	ldr r0, [fp, #-0x2d8]
	ldr r1, [fp, #-0x2dc]
	ldrb ip, [r3, #0x34]
	cmp r0, #0
	ldrb lr, [r3, #0x35]
	rsbne ip, ip, #0
	cmp r1, #0
	rsbne lr, lr, #0
	eor r3, ip, ip, asr #31
	sub r3, r3, ip, asr #31
	cmp r3, #0x3c
	bgt _0822F860
	eor r3, lr, lr, asr #31
	sub r3, r3, lr, asr #31
	cmp r3, #0x3c
	bgt _0822F860
	ldr r2, [fp, #-0x2b0]
	ldrh r3, [r2, #0x36]
	cmp r3, #0
	beq _0822F870
_0822F860:
	ldr r3, [fp, #-0x2d4]
	orr r3, r3, #0x300
	str r3, [fp, #-0x2d4]
	b _0822F87C
_0822F870:
	ldr r0, [fp, #-0x2d4]
	orr r0, r0, #0x100
	str r0, [fp, #-0x2d4]
_0822F87C:
	lsl r2, ip, #0x18
	asr r6, r2, #0x18
	lsl r3, lr, #0x18
	asr r7, r3, #0x18
	ldr r1, _0822F9FC @ =0x03003E40
	mov sb, r2
	ldr r2, [fp, #-0x2b0]
	mov sl, r3
	ldr r0, [r1]
	mov r4, r1
	ldrb r8, [r2, #0x36]
	cmp r0, #0x1f
	movgt r1, #0
	bgt _0822F8D8
	add r3, r0, #1
	str r3, [r4]
	ldr r2, _0822FA00 @ =0x030035B0
	lsl r3, r0, #2
	strb r8, [r2, r3]
	add r3, r3, r2
	strb r6, [r3, #1]
	mov r1, r0
	strb r7, [r3, #2]
_0822F8D8:
	mvn r0, #0x240
	sub r3, r0, #3
	sub r2, fp, #0x28
	strb r1, [r2, r3]
	tst r5, #0x8000
	beq _0822FA04
	rsb r2, ip, #0
	lsl r3, r2, #0x18
	asr ip, r3, #0x18
	asr r1, sl, #0x18
	ldr r0, [r4]
	mov r6, r2
	cmp r0, #0x1f
	movgt r2, #0
	bgt _0822F938
	add r3, r0, #1
	str r3, [r4]
	ldr r2, _0822FA00 @ =0x030035B0
	lsl r3, r0, #2
	strb r8, [r2, r3]
	add r3, r3, r2
	strb ip, [r3, #1]
	mov r2, r0
	strb r1, [r3, #2]
_0822F938:
	mvn r3, #0x240
	sub r3, r3, #2
	ldr r0, [r4]
	sub ip, fp, #0x28
	strb r2, [ip, r3]
	cmp r0, #0x1f
	asr ip, sb, #0x18
	rsb r2, lr, #0
	lsl r3, r2, #0x18
	asr r1, r3, #0x18
	mov lr, r2
	movgt r2, #0
	bgt _0822F990
	add r3, r0, #1
	str r3, [r4]
	ldr r2, _0822FA00 @ =0x030035B0
	lsl r3, r0, #2
	strb r8, [r2, r3]
	add r3, r3, r2
	strb ip, [r3, #1]
	mov r2, r0
	strb r1, [r3, #2]
_0822F990:
	mvn r3, #0x240
	sub r3, r3, #1
	ldr r0, [r4]
	sub r1, fp, #0x28
	strb r2, [r1, r3]
	cmp r0, #0x1f
	lsl r3, r6, #0x18
	asr ip, r3, #0x18
	lsl r2, lr, #0x18
	asr lr, r2, #0x18
	movgt r2, #0
	bgt _0822F9E4
	add r3, r0, #1
	str r3, [r4]
	ldr r2, _0822FA00 @ =0x030035B0
	lsl r3, r0, #2
	strb r8, [r2, r3]
	add r3, r3, r2
	strb ip, [r3, #1]
	mov r2, r0
	strb lr, [r3, #2]
_0822F9E4:
	mvn r3, #0x240
	sub ip, fp, #0x28
	strb r2, [ip, r3]
	b _0822FA28
	.align 2, 0
_0822F9F4: .4byte 0x030044B0
_0822F9F8: .4byte 0x030044AC
_0822F9FC: .4byte 0x03003E40
_0822FA00: .4byte 0x030035B0
_0822FA04:
	mvn r3, #0x240
	sub r3, r3, #2
	mvn r2, #0x240
	sub ip, fp, #0x28
	strb r1, [ip, r3]
	sub r2, r2, #1
	mov r3, ip
	strb r1, [r3, r2]
	strb r1, [ip, r0]
_0822FA28:
	ldr r0, [fp, #-0x2b0]
	ldrh r3, [r0, #0x36]
	ldr r1, _0822FC94 @ =0x085B0A08
	rsb r3, r3, #0
	and r2, r3, #0xff
	lsl r2, r2, #1
	add r3, r3, #0x40
	ldrsh r2, [r1, r2]
	and r3, r3, #0xff
	str r2, [fp, #-0x2cc]
	lsl r3, r3, #1
	ldrsh r1, [r1, r3]
	str r1, [fp, #-0x2d0]
_0822FA5C:
	ldr r1, [fp, #-0x2b0]
	ldrh r3, [r1, #0x38]
	mov r2, #0
	str r2, [fp, #-0x2c0]
	ldr r6, [r1, #0x4c]
	str r3, [fp, #-0x2f8]
	cmp r2, r3
	bge _0822FDEC
	str r5, [fp, #-0x2e4]
	and r3, r5, #0x40
	str r3, [fp, #-0x2e8]
_0822FA88:
	ldrb r5, [r6, #1]
	ldr r3, _0822FC98 @ =0x03004030
	ldr r2, _0822FC9C @ =0x03003FC0
	ldr r7, [fp, #-0x2d4]
	ldr ip, [fp, #-0x2e4]
	str r5, [fp, #-0x2e0]
	ldrb sl, [r3, r5]
	ldrb sb, [r2, r5]
	tst ip, #2
	bne _0822FB64
	ldr r0, [fp, #-0x2d8]
	ldrsh ip, [r6, #2]
	cmp r0, #0
	ldrsh r0, [r6, #4]
	add r4, ip, sl
	add lr, r0, sb
	movne r3, ip
	rsbne ip, r4, #0
	rsbne r4, r3, #0
	ldr r1, [fp, #-0x2dc]
	cmp r1, #0
	movne r3, r0
	rsbne r0, lr, #0
	rsbne lr, r3, #0
	ldr r2, [fp, #-0x2b4]
	ldr r3, [fp, #-0x2b8]
	ldr r5, [fp, #-0x2d8]
	add ip, ip, r2
	add r0, r0, r3
	ldrb r2, [r6]
	orr r3, r7, #0x10000000
	and r1, r2, #4
	cmp r5, r1
	movne r7, r3
	and r2, r2, #8
	ldr r1, [fp, #-0x2dc]
	orr r3, r7, #0x20000000
	cmp r1, r2
	ldr r2, [fp, #-0x2e8]
	movne r7, r3
	cmp r2, #0
	bne _0822FCDC
	sub r3, fp, #0x2b8
	ldm r3, {r3, r5}
	ldr r1, [fp, #-0x2c0]
	add lr, lr, r3
	cmn r4, r5
	add r8, r1, #1
	add r4, r6, #8
	bmi _0822FDD8
	cmp ip, #0xf0
	bgt _0822FDD8
	cmp lr, #0
	blt _0822FDD8
	b _0822FCD4
_0822FB64:
	ldrsh r3, [r6, #2]
	ldr r5, [fp, #-0x2b0]
	asr r8, sl, #1
	ldrb r2, [r5, #0x34]
	add r3, r3, r8
	muls r2, r3, r2
	asr r5, sb, #1
	asrpl r1, r2, #6
	rsbmi r3, r2, #0
	asrmi r3, r3, #6
	rsbmi r1, r3, #0
	ldr ip, [fp, #-0x2b0]
	ldrsh r3, [r6, #4]
	ldrb r2, [ip, #0x35]
	add r3, r3, r5
	muls r2, r3, r2
	mov lr, r1
	asrpl r2, r2, #6
	rsbmi r3, r2, #0
	asrmi r3, r3, #6
	rsbmi r2, r3, #0
	ldr r0, [fp, #-0x2d8]
	ldr ip, [fp, #-0x2d0]
	cmp r0, #0
	rsbne lr, lr, #0
	mul ip, lr, ip
	ldr r1, [fp, #-0x2dc]
	cmp r1, #0
	ldr r0, [fp, #-0x2cc]
	moveq r4, r2
	rsbne r4, r2, #0
	mul r0, r4, r0
	ldrb r2, [r6]
	tst r2, #4
	moveq r1, #0
	movne r1, #1
	tst r2, #8
	orr r3, r1, #2
	movne r1, r3
	sub r2, fp, #0x26c
	ldrb r3, [r2, r1]
	orr r7, r7, r3, lsl #25
	subs r3, ip, r0
	asrpl r2, r3, #0xc
	rsbmi r3, r3, #0
	asrmi r3, r3, #0xc
	rsbmi r2, r3, #0
	ldr r3, [fp, #-0x2d0]
	mul r3, r4, r3
	ldr ip, [fp, #-0x2cc]
	mlas r3, ip, lr, r3
	rsb ip, r8, r2
	asrpl r3, r3, #0xc
	rsbmi r3, r3, #0
	asrmi r3, r3, #0xc
	rsbmi r3, r3, #0
	rsb r0, r5, r3
	and r3, r7, #0x300
	cmp r3, #0x300
	bne _0822FCA0
	rsb ip, r8, ip
	ldr r1, [fp, #-0x2b4]
	rsb r0, r5, r0
	ldr r2, [fp, #-0x2b8]
	add r4, r6, #8
	ldr r3, [fp, #-0x2c0]
	add ip, ip, r1
	add r0, r0, r2
	adds sl, ip, sl, lsl #1
	add r8, r3, #1
	lsl r3, sb, #1
	bmi _0822FDD8
	cmp ip, #0xf0
	bgt _0822FDD8
	cmn r0, r3
	b _0822FCD0
	.align 2, 0
_0822FC94: .4byte 0x085B0A08
_0822FC98: .4byte 0x03004030
_0822FC9C: .4byte 0x03003FC0
_0822FCA0:
	sub r1, fp, #0x2b8
	ldm r1, {r1, r5}
	add r4, r6, #8
	ldr r2, [fp, #-0x2c0]
	add ip, ip, r5
	add r0, r0, r1
	cmn ip, sl
	add r8, r2, #1
	bmi _0822FDD8
	cmp ip, #0xf0
	bgt _0822FDD8
	cmn r0, sb
_0822FCD0:
	bmi _0822FDD8
_0822FCD4:
	cmp r0, #0xb4
	bgt _0822FDD8
_0822FCDC:
	ldr r3, [fp, #-0x2c8]
	mov r5, #0
	ldrh r2, [r6, #6]
	cmp r5, r3
	lsl r2, r2, #0x14
	ldr r3, [fp, #-0x2c4]
	lsr r2, r2, #0x14
	lsl r1, r3, #1
	sub r3, fp, #0x1e8
	strh r2, [r3, r1]
	ldr r1, [fp, #-0x2c0]
	ldr r2, [fp, #-0x2c4]
	and sb, r0, #0xff
	ldr r0, [fp, #-0x2b0]
	add r8, r1, #1
	ldrh r3, [r6, #6]
	lsl r2, r2, #2
	str r2, [fp, #-0x2fc]
	lsr r1, r3, #0xc
	ldr r3, [fp, #-0x2e0]
	sub lr, fp, #0x128
	ldr r2, [fp, #-0x2c4]
	add r4, r6, #8
	ldr r6, [r0, #0x3c]
	lsl sl, r3, #2
	add r0, r2, #1
	bge _0822FD74
	ldr r3, [fp, #-0x268]
	cmp r3, r1
	beq _0822FD74
	sub r2, fp, #0x268
_0822FD58:
	ldr r3, [fp, #-0x2c8]
	add r5, r5, #1
	cmp r5, r3
	bge _0822FD74
	ldr r3, [r2, r5, lsl #2]
	cmp r3, r1
	bne _0822FD58
_0822FD74:
	ldr r2, [fp, #-0x2c4]
	sub r3, fp, #0x228
	strb r5, [r3, r2]
	ldr r3, [fp, #-0x2c8]
	cmp r5, r3
	addeq r2, r5, #1
	streq r2, [fp, #-0x2c8]
	subeq r3, fp, #0x268
	streq r1, [r3, r5, lsl #2]
	lsl r2, ip, #0x17
	sub r5, fp, #0x2e0
	ldrb ip, [r5]
	ldr r1, _08230008 @ =0x03003FF0
	ldr r5, [fp, #-0x2c4]
	sub r3, fp, #0x168
	strb ip, [r3, r5]
	lsr r2, r2, #0x17
	ldr r3, [r1, sl]
	orr r2, sb, r2, lsl #16
	orr r3, r3, r6
	str r0, [fp, #-0x2c4]
	orr r3, r3, r2
	ldr r2, [fp, #-0x2fc]
	orr r3, r3, r7
	str r3, [lr, r2]
_0822FDD8:
	str r8, [fp, #-0x2c0]
	ldr r3, [fp, #-0x2f8]
	mov r6, r4
	cmp r8, r3
	blt _0822FA88
_0822FDEC:
	ldr r5, [fp, #-0x2c4]
	cmp r5, #0
	ble _08230130
	ldr ip, [fp, #-0x2b0]
	ldr r0, [fp, #-0x2c8]
	mov r5, #0
	ldr r6, [ip, #0x48]
	cmp r5, r0
	bge _0822FE48
_0822FE10:
	ldr r1, [fp, #-0x2b0]
	lsl r4, r5, #2
	ldrh r0, [r1, #0x3a]
	sub r3, fp, #0x268
	ldr r1, [r3, r4]
	add r0, r0, r1
	add r1, r6, r1, lsl #5
	bl FUN_0822f650
	sub r3, fp, #0x2ac
	str r0, [r3, r4]
	ldr r2, [fp, #-0x2c8]
	add r5, r5, #1
	cmp r5, r2
	blt _0822FE10
_0822FE48:
	ldr r5, [fp, #-0x2b0]
	ldr r3, [r5, #8]
	ands r2, r3, #0x20
	beq _0822FF98
	ldr ip, [fp, #-0x2c4]
	mov r5, #0
	cmp r5, ip
	bge _08230130
	sub r0, fp, #0x168
	str r0, [fp, #-0x2ec]
	sub sb, fp, #0x128
	ldr sl, _0823000C @ =0x03003588
	sub r8, fp, #0x1e8
	ldr r7, _08230010 @ =0x030035A4
_0822FE80:
	ldr r1, [fp, #-0x2ec]
	ldr r3, _08230014 @ =0x03003FD0
	lsl r2, r5, #1
	ldrh ip, [r8, r2]
	ldrb r0, [r1, r5]
	ldr r2, _0823000C @ =0x03003588
	ldr r1, _08230018 @ =0x03003FE0
	ldrb r6, [r3, r0]
	ldrb lr, [r1, r0]
	ldrsh r3, [r2]
	ldr r1, _0823001C @ =0x03003FB0
	add r3, r3, r6
	ldrb r0, [r1, r0]
	cmp r3, #0x400
	mvnge r3, #0
	bge _0822FEFC
	ldr r2, [r7]
	ldr r3, [fp, #-0x2b0]
	lsl r2, r2, #3
	add r2, r2, #0x2000000
	ldr r1, [r3, #0x50]
	add r2, r2, #0x39000
	add r1, r1, ip, lsl #5
	lsl r3, r0, #0x10
	str r1, [r2]
	orr r3, r3, lr, lsl #5
	str r3, [r2, #4]
	ldr r1, [r7]
	mov r3, #0
	add r1, r1, #1
	str r1, [r7]
_0822FEFC:
	cmp r3, #0
	blt _08230130
	ldr r4, _08230020 @ =0x03003A38
	ldrsh r0, [sl]
	ldr r1, [fp, #-0x2b0]
	ldr lr, [r4]
	sub r3, fp, #0x228
	ldrb ip, [r1, #0x1a]
	sub r2, fp, #0x2ac
	ldrb r1, [r3, r5]
	cmp lr, #0x7f
	ldr r3, [r2, r1, lsl #2]
	orr r0, r0, ip, lsl #10
	ldr r2, [sb, r5, lsl #2]
	orr ip, r0, r3, lsl #12
	bgt _0822FF68
	add r3, lr, #1
	str r3, [r4]
	ldr r1, _08230024 @ =0x03003630
	ldr r0, _08230028 @ =0x03002CA4
	lsl r3, lr, #3
	str r2, [r1, r3]
	ldr r2, [r0]
	add r3, r3, r1
	strh ip, [r3, #4]
	orr r2, r2, #1
	str r2, [r0]
_0822FF68:
	ldr r3, _0823002C @ =0x0300357C
	ldrh r2, [r3]
	add r2, r2, r6
	strh r2, [r3]
	ldrh r1, [sl]
	add r1, r1, r6
	strh r1, [sl]
	ldr r2, [fp, #-0x2c4]
	add r5, r5, #1
	cmp r5, r2
	blt _0822FE80
	b _08230130
_0822FF98:
	ldr r3, [fp, #-0x2c4]
	mov r5, r2
	cmp r5, r3
	bge _08230130
	sub ip, fp, #0x168
	str ip, [fp, #-0x2f0]
	sub r0, fp, #0x128
	str r0, [fp, #-0x2f4]
	ldr sl, _0823000C @ =0x03003588
	sub sb, fp, #0x1e8
	ldr r8, _08230010 @ =0x030035A4
_0822FFC4:
	ldr r1, [fp, #-0x2f0]
	ldr r3, _08230014 @ =0x03003FD0
	lsl r2, r5, #1
	ldrh ip, [sb, r2]
	ldrb r0, [r1, r5]
	ldr r2, _0823000C @ =0x03003588
	ldr r1, _08230018 @ =0x03003FE0
	ldrb r6, [r3, r0]
	ldrb lr, [r1, r0]
	ldrsh r3, [r2]
	ldr r1, _0823001C @ =0x03003FB0
	add r3, r3, r6
	ldrb r0, [r1, r0]
	cmp r3, #0x400
	blt _08230030
	mvn r3, #0
	b _0823006C
	.align 2, 0
_08230008: .4byte 0x03003FF0
_0823000C: .4byte 0x03003588
_08230010: .4byte 0x030035A4
_08230014: .4byte 0x03003FD0
_08230018: .4byte 0x03003FE0
_0823001C: .4byte 0x03003FB0
_08230020: .4byte 0x03003A38
_08230024: .4byte 0x03003630
_08230028: .4byte 0x03002CA4
_0823002C: .4byte 0x0300357C
_08230030:
	ldr r2, [r8]
	ldr r3, [fp, #-0x2b0]
	lsl r2, r2, #3
	add r2, r2, #0x2000000
	ldr r1, [r3, #0x50]
	add r2, r2, #0x39000
	add r1, r1, ip, lsl #5
	lsl r3, r0, #0x10
	str r1, [r2]
	orr r3, r3, lr, lsl #5
	str r3, [r2, #4]
	ldr r1, [r8]
	mov r3, #0
	add r1, r1, #1
	str r1, [r8]
_0823006C:
	cmp r3, #0
	blt _08230130
	ldr r7, _0823011C @ =0x03003A3C
	ldrsh r0, [sl]
	ldr r1, [fp, #-0x2b0]
	ldr ip, [r7]
	ldrb r4, [r1, #0x1a]
	sub r3, fp, #0x228
	ldrb r1, [r3, r5]
	sub r2, fp, #0x2ac
	ldr r3, [r2, r1, lsl #2]
	cmp ip, #0x7f
	ldr r2, [fp, #-0x2f4]
	orr r0, r0, r4, lsl #10
	ldr lr, [r2, r5, lsl #2]
	orr r0, r0, r3, lsl #12
	bgt _082300F0
	add r3, ip, #1
	str r3, [r7]
	ldr r2, _08230120 @ =0x03003A40
	lsl r1, ip, #3
	str lr, [r1, r2]
	add r1, r1, r2
	strh r0, [r1, #4]
	ldr r3, [fp, #-0x2bc]
	ldr ip, _08230124 @ =0x03003A30
	add r2, r3, #0x80
	lsl r0, r4, #1
	ldrh r3, [ip, r0]
	lsl r2, r2, #8
	strh r2, [r1, #6]
	add r3, r3, #1
	strh r3, [ip, r0]
_082300F0:
	ldr r3, _08230128 @ =0x0300357C
	ldrh r2, [r3]
	add r2, r2, r6
	strh r2, [r3]
	ldrh r1, [sl]
	add r1, r1, r6
	strh r1, [sl]
	ldr ip, [fp, #-0x2c4]
	add r5, r5, #1
	cmp r5, ip
	b _0823012C
	.align 2, 0
_0823011C: .4byte 0x03003A3C
_08230120: .4byte 0x03003A40
_08230124: .4byte 0x03003A30
_08230128: .4byte 0x0300357C
_0823012C:
	blt _0822FFC4
_08230130:
	ldmdb fp, {r4, r5, r6, r7, r8, sb, sl, fp, sp, pc}
