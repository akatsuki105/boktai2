	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r2, #0
	mov r4, sp
	adds r3, r1, #0
	adds r3, #0xc
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _081F46AC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _081F46AC
	ldr r0, _081F46A0 @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _081F46A4 @ =0x000003FF
	ands r1, r2
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _081F46A8 @ =0x0203B400
	adds r1, r1, r0
	ldrb r0, [r1]
	b _081F46BC
	.align 2, 0
_081F46A0: .4byte 0x030046B8
_081F46A4: .4byte 0x000003FF
_081F46A8: .4byte 0x0203B400
_081F46AC:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
_081F46BC:
	adds r5, r6, #0
	adds r5, #0x1c
	lsls r4, r0, #0x18
	lsrs r4, r4, #0x18
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081f4a08
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081f4a08
	adds r2, r6, #0
	adds r2, #0x58
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, #0x50
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #3
	strb r0, [r1]
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
