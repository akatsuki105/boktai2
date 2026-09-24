	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x44
	adds r5, r0, #0
	movs r0, #1
	str r0, [sp, #0x2c]
	ldr r1, _0809D2F0 @ =0x00000E2B
	adds r0, r5, r1
	ldrb r0, [r0]
	bl GetWeaponID
	str r0, [sp, #0x34]
	ldr r0, _0809D2F4 @ =0x000002DF
	mov r8, r0
	str r0, [sp, #0x3c]
	movs r1, #0xf7
	lsls r1, r1, #4
	adds r0, r5, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	add r0, sp, #0xc
	bl FUN_0809d240
	add r4, sp, #0x1c
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_0809d240
	movs r2, #0
	add r1, sp, #0x2c
	str r2, [r1, #4]
	add r6, sp, #0x34
	str r2, [r6, #4]
	add r3, sp, #0x3c
	mov r0, r8
	str r0, [r3, #4]
	add r0, sp, #0xc
	strh r2, [r0, #8]
	strh r2, [r0, #0xa]
	strh r2, [r0, #0xc]
	strh r2, [r4, #8]
	strh r2, [r4, #0xa]
	strh r2, [r4, #0xc]
	ldr r0, _0809D2F8 @ =0x00000E58
	adds r5, r5, r0
	str r6, [sp]
	str r3, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	adds r0, r5, #0
	add r2, sp, #0xc
	adds r3, r4, #0
	bl FUN_080b9a28
	ldr r0, _0809D2FC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809D2F0: .4byte 0x00000E2B
_0809D2F4: .4byte 0x000002DF
_0809D2F8: .4byte 0x00000E58
_0809D2FC: .4byte 0x0000038A
