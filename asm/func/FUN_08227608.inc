	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r7, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0822763C
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _08227638 @ =0x00000F14
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #1
	b _0822763E
	.align 2, 0
_08227638: .4byte 0x00000F14
_0822763C:
	movs r0, #0
_0822763E:
	cmp r0, #0
	bne _08227644
	b _08227764
_08227644:
	ldr r0, _082276A0 @ =0x00000F15
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0xd
	strb r0, [r1]
	ldr r1, _082276A4 @ =0x00000DE4
	adds r4, r7, r1
	adds r1, #0x50
	adds r0, r7, r1
	ldr r1, [r0]
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #0xd
	movs r3, #0
	bl FUN_08236fac
	ldr r2, _082276A8 @ =0x00000DC8
	adds r0, r7, r2
	movs r1, #0x8d
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _082276AC @ =0x00000D9C
	adds r5, r7, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082276B0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _082276B8
	.align 2, 0
_082276A0: .4byte 0x00000F15
_082276A4: .4byte 0x00000DE4
_082276A8: .4byte 0x00000DC8
_082276AC: .4byte 0x00000D9C
_082276B0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082276B8:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _082276DC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082276E4
_082276DC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082276E4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0822771C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08227754
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08227720
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08227714
	ldrb r0, [r4, #5]
_08227714:
	subs r0, #1
	strh r0, [r4, #8]
	b _08227730
	.align 2, 0
_0822771C: .4byte 0x0000FFFF
_08227720:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08227730
	strh r1, [r4, #8]
_08227730:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08227754
	movs r0, #1
	strb r0, [r4, #7]
_08227754:
	ldr r0, _082277A0 @ =0x00000F3C
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _082277A4 @ =0x00000F3E
	adds r1, r7, r2
	movs r0, #0xf
	strh r0, [r1]
_08227764:
	ldr r0, _082277A0 @ =0x00000F3C
	adds r4, r7, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _082277A4 @ =0x00000F3E
	adds r1, r7, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Mod
	cmp r0, #0
	beq _08227784
	b _082279A8
_08227784:
	strh r0, [r4]
	ldr r0, _082277A8 @ =0x00000D9C
	adds r2, r7, r0
	ldr r1, [r2]
	movs r3, #1
	adds r0, r1, #0
	ands r0, r3
	cmp r0, #0
	beq _082277AC
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _082277AE
	.align 2, 0
_082277A0: .4byte 0x00000F3C
_082277A4: .4byte 0x00000F3E
_082277A8: .4byte 0x00000D9C
_082277AC:
	orrs r1, r3
_082277AE:
	str r1, [r2]
	ldr r2, _082279B8 @ =0x00000F3E
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _082277C2
	b _082279A8
_082277C2:
	movs r5, #0xa
	ldr r0, _082279BC @ =0x00000DB8
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x80
	lsls r1, r1, #2
	mov r8, r1
	movs r4, #8
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	movs r6, #4
	str r6, [sp, #0xc]
	movs r1, #1
	mov r2, r8
	movs r3, #0x30
	bl FUN_08015d3c
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sb
	movs r1, #1
	mov r2, r8
	movs r3, #0x30
	bl FUN_08015d3c
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sb
	movs r1, #1
	mov r2, r8
	movs r3, #0x30
	bl FUN_08015d3c
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r6, [sp, #0xc]
	mov r0, sb
	movs r1, #1
	mov r2, r8
	movs r3, #0x30
	bl FUN_08015d3c
	movs r4, #0x3c
	str r4, [sp]
	str r5, [sp, #4]
	movs r2, #3
	mov r8, r2
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	movs r6, #5
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	movs r3, #0x20
	bl FUN_080149dc
	str r4, [sp]
	str r5, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	movs r3, #0x40
	bl FUN_080149dc
	str r4, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	movs r3, #0x60
	bl FUN_080149dc
	str r4, [sp]
	str r5, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	movs r3, #0x80
	bl FUN_080149dc
	str r4, [sp]
	str r5, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	movs r3, #0xa0
	bl FUN_080149dc
	str r4, [sp]
	str r5, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	movs r3, #0xc0
	bl FUN_080149dc
	str r4, [sp]
	str r5, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	movs r3, #0xe0
	bl FUN_080149dc
	movs r3, #0x80
	lsls r3, r3, #1
	str r4, [sp]
	str r5, [sp, #4]
	mov r0, r8
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	str r6, [sp, #0x10]
	str r4, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #1
	movs r1, #3
	mov r2, sb
	bl FUN_080149dc
	ldr r1, _082279C0 @ =0x00000DF4
	adds r0, r7, r1
	bl FUN_080136b4
	ldr r0, _082279C4 @ =0x00000D9C
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _082279C8 @ =0x00000F16
	adds r4, r7, r1
	ldrb r0, [r4]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r2, _082279CC @ =0x00000F18
	adds r3, r7, r2
	strh r0, [r3]
	movs r2, #1
	ldrb r1, [r4]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r4]
	ldrh r1, [r4]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x20
	orrs r0, r1
	strh r0, [r4]
	ldrh r0, [r3]
	cmp r0, #3
	bne _08227972
	ldrb r1, [r4]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08227972
	ldr r1, _082279D0 @ =0x00000DEC
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r2, _082279D4 @ =0x00000F42
	adds r0, r7, r2
	strb r1, [r0]
	ldr r1, _082279D8 @ =0x00000DF2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r7, r2
	strb r1, [r0]
_08227972:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r7, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	movs r6, #4
	ldr r4, _082279DC @ =FUN_08224dd0
	movs r5, #1
	adds r1, r7, #0
	adds r1, #0xc4
	movs r7, #0
	movs r3, #0xf
_0822798E:
	ldrb r2, [r1, #5]
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq _082279A0
	str r4, [r1]
	adds r0, r5, #0
	orrs r0, r2
	strb r0, [r1, #5]
_082279A0:
	adds r1, #0xd8
	subs r3, #1
	cmp r3, #0
	bge _0822798E
_082279A8:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082279B8: .4byte 0x00000F3E
_082279BC: .4byte 0x00000DB8
_082279C0: .4byte 0x00000DF4
_082279C4: .4byte 0x00000D9C
_082279C8: .4byte 0x00000F16
_082279CC: .4byte 0x00000F18
_082279D0: .4byte 0x00000DEC
_082279D4: .4byte 0x00000F42
_082279D8: .4byte 0x00000DF2
_082279DC: .4byte FUN_08224dd0
