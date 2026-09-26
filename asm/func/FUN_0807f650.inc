	push {r4, r5, lr}
	adds r5, r0, #0
	mov ip, r1
	adds r1, #0x29
	mov r0, ip
	adds r0, #0x2d
	ldrb r0, [r0]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	mov r0, ip
	ldrh r3, [r0, #0x30]
	ldr r2, _0807F688 @ =0x085B0A08
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _0807F68C
	asrs r3, r0, #0xc
	b _0807F692
	.align 2, 0
_0807F688: .4byte 0x085B0A08
_0807F68C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0807F692:
	ldr r2, [r5, #0x18]
	ldrh r0, [r2, #0x2c]
	adds r0, r0, r3
	mov r3, ip
	strh r0, [r3, #0x18]
	ldrh r1, [r3, #0x30]
	mov r0, ip
	adds r0, #0x29
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0807F6B6
	asrs r1, r0, #0xc
	b _0807F6BC
_0807F6B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807F6BC:
	ldrh r0, [r2, #0x30]
	adds r0, r0, r1
	mov r1, ip
	strh r0, [r1, #0x1c]
	movs r2, #0x97
	lsls r2, r2, #3
	adds r0, r5, r2
	adds r1, #0x2b
	ldrh r2, [r0]
	ldrb r1, [r1]
	cmp r2, r1
	blo _0807F700
	movs r0, #7
	ands r0, r2
	cmp r0, #0
	bne _0807F6EA
	mov r1, ip
	adds r1, #0x2d
	ldrb r0, [r1]
	cmp r0, #2
	bls _0807F6EA
	subs r0, #1
	strb r0, [r1]
_0807F6EA:
	mov r3, ip
	ldrh r0, [r3, #0x30]
	adds r0, #6
	strh r0, [r3, #0x30]
	mov r1, ip
	adds r1, #0x2a
	ldrh r0, [r3, #0x1a]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r3, #0x1a]
	b _0807F708
_0807F700:
	mov r1, ip
	ldrh r0, [r1, #0x30]
	adds r0, #1
	strh r0, [r1, #0x30]
_0807F708:
	mov r0, ip
	adds r0, #0x2c
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #0
	bne _0807F724
	adds r0, r5, #0
	adds r0, #0xf4
	ldr r1, [r0]
	mov r0, ip
	movs r2, #4
	bl FUN_0822dafc
	b _0807F736
_0807F724:
	cmp r1, #4
	bne _0807F736
	adds r0, r5, #0
	adds r0, #0xf4
	ldr r1, [r0]
	mov r0, ip
	movs r2, #5
	bl FUN_0822dafc
_0807F736:
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _0807F748
	movs r0, #0
	strb r0, [r4]
_0807F748:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
