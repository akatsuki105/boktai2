	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xdc
	ldr r2, _08087280 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x5a
	orrs r0, r3
	ldr r4, _08087284 @ =0x0000FFFF
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ands r0, r4
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	ldrb r0, [r5, #0x1a]
	adds r4, r1, #0
	cmp r0, #3
	beq _08087238
	ldrh r0, [r5, #0x1c]
	movs r3, #2
	cmp r0, #0
	bne _0808723A
_08087238:
	movs r3, #0x10
_0808723A:
	ldrh r1, [r5, #0x18]
	ldr r2, _08087288 @ =0x00004081
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	ldr r1, _0808728C @ =FUN_08087528
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r1, r5, #0
	adds r1, #0x48
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08087280: .4byte 0xFFFF0000
_08087284: .4byte 0x0000FFFF
_08087288: .4byte 0x00004081
_0808728C: .4byte FUN_08087528
