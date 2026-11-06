	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	str r1, [sp, #0x1c]
	str r2, [sp, #0x20]
	mov sb, r3
	ldr r0, [sp, #0x50]
	mov sl, r0
	ldr r2, _081F6100 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081F6104 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	mov r8, r1
	adds r5, r6, #0
	adds r5, #0x1c
	adds r4, r6, #0
	adds r4, #0x48
	movs r7, #5
_081F6078:
	movs r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	mov r2, r8
	str r2, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _081F6108 @ =0x00002401
	movs r3, #0
	bl Hitbox_Init
	mov r0, sb
	str r0, [sp]
	ldr r1, [sp, #0x44]
	str r1, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	movs r3, #0
	bl Hitbox_SetAttack
	adds r0, r4, #0
	ldr r1, _081F610C @ =Entity081f73ec_OnHit
	adds r2, r6, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	movs r2, #0x92
	lsls r2, r2, #1
	adds r5, r5, r2
	adds r4, r4, r2
	subs r7, #1
	cmp r7, #0
	bge _081F6078
	adds r7, r6, #0
	adds r7, #0x1c
	adds r4, r6, #0
	adds r4, #0x98
	adds r5, r6, #0
_081F60D0:
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _081F6110 @ =0x00005005
	movs r3, #0
	bl Hitbox_Init
	ldr r2, _081F6114 @ =0x000005B4
	adds r0, r6, r2
	cmp r5, r0
	bne _081F611C
	ldr r1, _081F6118 @ =0x0000064C
	adds r0, r6, r1
	ldr r1, [sp, #0x48]
	ldr r2, [sp, #0x4c]
	mov r3, sl
	bl Hitbox_SetPowerAndAttributes
	b _081F612A
	.align 2, 0
_081F6100: .4byte 0xFFFF0000
_081F6104: .4byte 0x0000FFFF
_081F6108: .4byte 0x00002401
_081F610C: .4byte Entity081f73ec_OnHit
_081F6110: .4byte 0x00005005
_081F6114: .4byte 0x000005B4
_081F6118: .4byte 0x0000064C
_081F611C:
	adds r0, r4, #0
	ldr r2, [sp, #0x48]
	lsls r1, r2, #1
	ldr r2, [sp, #0x4c]
	mov r3, sl
	bl Hitbox_SetPowerAndAttributes
_081F612A:
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	ldr r1, _081F6168 @ =Entity081f73ec_OnHurt
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0x92
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r5, r5, r0
	ldr r1, _081F616C @ =0x000005B4
	adds r0, r6, r1
	cmp r5, r0
	ble _081F60D0
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F6168: .4byte Entity081f73ec_OnHurt
_081F616C: .4byte 0x000005B4
