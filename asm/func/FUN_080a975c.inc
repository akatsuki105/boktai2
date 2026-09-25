	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_0822dafc
	ldr r0, _080A97F8 @ =0x0203B400
	mov sb, r0
	ldr r5, _080A97FC @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080A9800 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x10
	bl Mod
	adds r0, #8
	movs r6, #0
	strh r0, [r4, #0x18]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x10
	bl Mod
	adds r0, #0x18
	strh r0, [r4, #0x1a]
	strh r6, [r4, #0x1c]
	strh r6, [r4, #0x2c]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #2
	bl Mod
	adds r0, #2
	rsbs r0, r0, #0
	strh r0, [r4, #0x2e]
	strh r6, [r4, #0x30]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r6, [r4, #0x28]
	ldr r0, _080A9804 @ =FUN_080a971c
	str r0, [r4, #0x38]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A97F8: .4byte 0x0203B400
_080A97FC: .4byte 0x030046B8
_080A9800: .4byte 0x000003FF
_080A9804: .4byte FUN_080a971c
