	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _080C6B58
	b _080C6C6E
_080C6B58:
	ldr r3, _080C6BB8 @ =0x000025FB
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080C6BCC
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	subs r0, #0xd0
	lsls r0, r0, #0x10
	ldr r2, _080C6BBC @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	movs r3, #0xbb
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	ldr r2, _080C6BC0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C6BC4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C6BC8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x18
	bl Mod
	adds r6, r0, #0
	adds r6, #0x54
	b _080C6C1E
	.align 2, 0
_080C6BB8: .4byte 0x000025FB
_080C6BBC: .4byte 0xFFFF0000
_080C6BC0: .4byte 0x030046B8
_080C6BC4: .4byte 0x000003FF
_080C6BC8: .4byte 0x0203B400
_080C6BCC:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrh r0, [r0]
	adds r0, #0x90
	lsls r0, r0, #0x10
	ldr r2, _080C6C78 @ =0xFFFF0000
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xbb
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	ldr r2, _080C6C7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C6C80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C6C84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x18
	bl Mod
	adds r6, r0, #0
	adds r6, #0x14
_080C6C1E:
	movs r0, #0x8a
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r4, [r0]
	ldr r2, _080C6C7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C6C80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C6C84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	adds r2, r0, #0
	movs r3, #0xc8
	lsls r3, r3, #5
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #0x14
	str r1, [sp]
	str r2, [sp, #4]
	add r1, sp, #8
	adds r2, r4, #0
	adds r3, r6, #0
	bl CreateHomingLaser
	ldr r0, _080C6C88 @ =0x000025FB
	adds r2, r5, r0
	ldrb r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2]
_080C6C6E:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080C6C78: .4byte 0xFFFF0000
_080C6C7C: .4byte 0x030046B8
_080C6C80: .4byte 0x000003FF
_080C6C84: .4byte 0x0203B400
_080C6C88: .4byte 0x000025FB
