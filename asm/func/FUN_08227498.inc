	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r7, r1
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _082274C8
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldr r2, _082274C4 @ =0x00000F14
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #1
	b _082274CA
	.align 2, 0
_082274C4: .4byte 0x00000F14
_082274C8:
	movs r0, #0
_082274CA:
	cmp r0, #0
	bne _082274D0
	b _082275F6
_082274D0:
	ldr r0, _0822752C @ =0x00000F15
	adds r1, r7, r0
	movs r2, #0
	movs r0, #0xc
	strb r0, [r1]
	ldr r1, _08227530 @ =0x00000DE4
	adds r4, r7, r1
	adds r1, #0x50
	adds r0, r7, r1
	ldr r1, [r0]
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #0xc
	movs r3, #0
	bl FUN_08236fac
	ldr r2, _08227534 @ =0x00000DC8
	adds r0, r7, r2
	movs r1, #0x8d
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldr r0, _08227538 @ =0x00000D9C
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
	beq _0822753C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08227544
	.align 2, 0
_0822752C: .4byte 0x00000F15
_08227530: .4byte 0x00000DE4
_08227534: .4byte 0x00000DC8
_08227538: .4byte 0x00000D9C
_0822753C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08227544:
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
	beq _08227568
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08227570
_08227568:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08227570:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082275A8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _082275E0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082275AC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082275A0
	ldrb r0, [r4, #5]
_082275A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _082275BC
	.align 2, 0
_082275A8: .4byte 0x0000FFFF
_082275AC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _082275BC
	strh r1, [r4, #8]
_082275BC:
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
	bne _082275E0
	movs r0, #1
	strb r0, [r4, #7]
_082275E0:
	ldr r0, _08227600 @ =0x00000DA3
	adds r1, r7, r0
	movs r0, #3
	strb r0, [r1]
	ldr r1, _08227604 @ =0x00000D9C
	adds r2, r7, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
_082275F6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08227600: .4byte 0x00000DA3
_08227604: .4byte 0x00000D9C
