	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r1, _08195D44 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #3
	bl Mod
	ldr r2, _08195D48 @ =0x00000AFC
	adds r3, r4, r2
	ldr r1, _08195D4C @ =0x085ADD90
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r1, [r3]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _08195D50 @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r5
	orrs r3, r1
	str r3, [sp]
	ldr r1, [r4, #0x18]
	ldrh r2, [r1, #0x2e]
	adds r2, #0xdc
	lsls r2, r2, #0x10
	ldr r1, _08195D54 @ =0x0000FFFF
	ands r1, r3
	orrs r1, r2
	str r1, [sp]
	movs r2, #0xb0
	lsls r2, r2, #4
	adds r1, r4, r2
	ldr r2, [r0]
	ldrh r0, [r1]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [sp, #4]
	ldr r0, _08195D58 @ =0x00000BE4
	adds r4, r4, r0
	adds r0, r4, #0
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08195D44: .4byte 0x00000CEC
_08195D48: .4byte 0x00000AFC
_08195D4C: .4byte 0x085ADD90
_08195D50: .4byte 0xFFFF0000
_08195D54: .4byte 0x0000FFFF
_08195D58: .4byte 0x00000BE4
