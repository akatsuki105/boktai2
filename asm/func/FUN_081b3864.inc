	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _081B3910 @ =0x0000067E
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r3, _081B3914 @ =0x0000067C
	adds r0, r5, r3
	movs r2, #0
	mov sb, r2
	strh r1, [r0]
	movs r3, #1
	mov r8, r3
	ldr r0, _081B3918 @ =0x0000065C
	adds r5, r5, r0
	ldrh r1, [r5]
	movs r3, #0
	mov r0, r8
	orrs r0, r1
	movs r6, #3
	rsbs r6, r6, #0
	ands r0, r6
	strh r0, [r5]
	movs r2, #4
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xf
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r3, [r0]
	ldr r3, _081B391C @ =0x0000046A
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _081B3920 @ =0x00000484
	adds r0, r4, r1
	mov r2, sb
	str r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	movs r2, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x9c
	adds r3, #0x4a
	adds r0, r4, r3
	ldrb r0, [r0]
	eors r2, r0
	subs r3, #2
	adds r0, r4, r3
	adds r0, r0, r2
	ldrb r2, [r0]
	mov r0, sb
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #0
	bl Mover_SetPath
	adds r0, r4, #0
	bl BokuLink_RouteAwayFromPlayer
	ldrh r0, [r5]
	ands r6, r0
	strh r6, [r5]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081B3910: .4byte 0x0000067E
_081B3914: .4byte 0x0000067C
_081B3918: .4byte 0x0000065C
_081B391C: .4byte 0x0000046A
_081B3920: .4byte 0x00000484
