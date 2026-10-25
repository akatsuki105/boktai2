	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0x48
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0xc4
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, [r0, #0xc]
	ldr r0, [r0, #8]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r6, _080235AC @ =0x085AAACC
	ldr r2, _080235B0 @ =0x00000167
	adds r2, r2, r7
	mov r8, r2
	ldrb r4, [r2]
	adds r4, #0x20
	movs r5, #0xff
	ands r4, r5
	asrs r4, r4, #6
	adds r4, #1
	movs r0, #3
	ands r4, r0
	adds r0, r7, #0
	adds r0, #0x50
	bl Duneyrr_GetQuadrant
	ldr r3, _080235B4 @ =0x0000016F
	adds r1, r7, r3
	lsls r4, r4, #1
	ldrb r1, [r1]
	adds r4, r4, r1
	lsls r0, r0, #3
	adds r4, r4, r0
	adds r4, r4, r6
	ldrb r1, [r4]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	adds r3, #0x21
	adds r2, r7, r3
	mov r0, r8
	ldrb r3, [r0]
	ldr r1, _080235B8 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #0xc
	cmp r0, #0
	blt _080235BC
	asrs r1, r0, #0xc
	b _080235C2
	.align 2, 0
_080235AC: .4byte 0x085AAACC
_080235B0: .4byte 0x00000167
_080235B4: .4byte 0x0000016F
_080235B8: .4byte gSineTable
_080235BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080235C2:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	ldr r1, _080235E0 @ =gSineTable
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #5
	muls r0, r1, r0
	cmp r0, #0
	blt _080235E4
	asrs r0, r0, #0xc
	b _080235EA
	.align 2, 0
_080235E0: .4byte gSineTable
_080235E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080235EA:
	strh r0, [r2, #4]
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r0, [r1]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	ldr r3, _0802363C @ =0x0000016F
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #9
	movs r1, #0x80
	lsls r1, r1, #3
	adds r0, r0, r1
	adds r3, #0x23
	adds r1, r7, r3
	strh r0, [r1]
	movs r1, #0xb8
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08023670
	cmp r0, #1
	bgt _08023640
	cmp r0, #0
	beq _0802364A
	b _080236E2
	.align 2, 0
_0802363C: .4byte 0x0000016F
_08023640:
	cmp r0, #2
	beq _08023690
	cmp r0, #3
	beq _080236BA
	b _080236E2
_0802364A:
	movs r3, #0
	ldrsh r1, [r2, r3]
	ldr r0, _08023658 @ =0x0000017F
	cmp r1, r0
	bgt _0802365C
	adds r0, #1
	b _08023664
	.align 2, 0
_08023658: .4byte 0x0000017F
_0802365C:
	movs r0, #0xb8
	lsls r0, r0, #4
	cmp r1, r0
	ble _08023666
_08023664:
	strh r0, [r2]
_08023666:
	movs r0, #0xca
	lsls r0, r0, #1
	adds r1, r7, r0
	subs r0, #0x94
	b _080236E0
_08023670:
	movs r0, #0xc0
	lsls r0, r0, #4
	strh r0, [r2]
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r3, #0
	ldrsh r2, [r1, r3]
	ldr r0, _0802368C @ =0x0000017F
	cmp r2, r0
	bgt _080236D8
	adds r0, #1
	b _080236E0
	.align 2, 0
_0802368C: .4byte 0x0000017F
_08023690:
	movs r0, #0
	ldrsh r1, [r2, r0]
	ldr r0, _080236A0 @ =0x0000017F
	cmp r1, r0
	bgt _080236A4
	adds r0, #1
	b _080236AC
	.align 2, 0
_080236A0: .4byte 0x0000017F
_080236A4:
	movs r0, #0xb8
	lsls r0, r0, #4
	cmp r1, r0
	ble _080236AE
_080236AC:
	strh r0, [r2]
_080236AE:
	movs r2, #0xca
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0xc0
	lsls r0, r0, #4
	b _080236E0
_080236BA:
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r2]
	movs r3, #0xca
	lsls r3, r3, #1
	adds r1, r7, r3
	movs r0, #0
	ldrsh r2, [r1, r0]
	ldr r0, _080236D4 @ =0x0000017F
	cmp r2, r0
	bgt _080236D8
	adds r0, #1
	b _080236E0
	.align 2, 0
_080236D4: .4byte 0x0000017F
_080236D8:
	movs r0, #0xb8
	lsls r0, r0, #4
	cmp r2, r0
	ble _080236E2
_080236E0:
	strh r0, [r1]
_080236E2:
	ldr r1, _08023734 @ =0x0000016F
	adds r1, r1, r7
	mov r8, r1
	ldrb r0, [r1]
	cmp r0, #0
	bne _08023778
	ldr r5, _08023738 @ =0x085AAACC
	ldr r2, _0802373C @ =0x00000167
	adds r6, r7, r2
	ldrb r4, [r6]
	adds r4, #0x20
	movs r0, #0xff
	ands r4, r0
	asrs r4, r4, #6
	adds r4, #1
	movs r0, #3
	ands r4, r0
	mov r0, sb
	adds r0, #8
	bl Duneyrr_GetQuadrant
	mov r3, r8
	ldrb r1, [r3]
	lsls r4, r4, #1
	adds r4, #1
	adds r1, r1, r4
	lsls r0, r0, #3
	adds r1, r1, r0
	adds r1, r1, r5
	ldrb r1, [r1]
	movs r2, #0xb8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _08023754
	cmp r0, #1
	bgt _08023740
	cmp r0, #0
	beq _0802374A
	b _08023778
	.align 2, 0
_08023734: .4byte 0x0000016F
_08023738: .4byte 0x085AAACC
_0802373C: .4byte 0x00000167
_08023740:
	cmp r0, #2
	beq _0802375E
	cmp r0, #3
	beq _08023768
	b _08023778
_0802374A:
	cmp r1, #1
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_08023754:
	cmp r1, #2
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_0802375E:
	cmp r1, #3
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_08023768:
	cmp r1, #0
	bne _08023772
	ldrb r0, [r6]
	adds r0, #0x40
	b _08023776
_08023772:
	ldrb r0, [r6]
	subs r0, #0x40
_08023776:
	strb r0, [r6]
_08023778:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
