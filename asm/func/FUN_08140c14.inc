	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _08140CC0 @ =0x00000666
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	str r6, [sp]
	mov r0, sp
	ldr r2, _08140CC4 @ =0x05000002
	bl CpuSet
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r1, #8
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	movs r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08140CC8 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r6, [r0]
	ldr r0, _08140CCC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl ParticleShadow_Show
	ldr r0, _08140CD0 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl EnemyBat_BeginCurveMove
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140CC0: .4byte 0x00000666
_08140CC4: .4byte 0x05000002
_08140CC8: .4byte 0x0000046A
_08140CCC: .4byte 0x0000046C
_08140CD0: .4byte 0x03002BE0
