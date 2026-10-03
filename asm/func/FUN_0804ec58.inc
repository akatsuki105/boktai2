	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	beq _0804EC88
	movs r0, #0
	strb r0, [r4, #0x19]
	movs r1, #4
	str r1, [sp]
	ldr r1, _0804ECC8 @ =0x0000FFFF
	str r1, [sp, #4]
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	movs r0, #0xde
	bl PlaySound_082406e0
	bl FUN_0804e5e8
_0804EC88:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x14
	bne _0804EC92
	bl FUN_0804e604
_0804EC92:
	ldr r0, [r4, #0x1c]
	cmp r0, #0x13
	bls _0804ECBA
	bl FUN_0804ba3c
	cmp r0, #0
	bne _0804ECBA
	ldr r0, [r4, #0x2c]
	cmp r0, #0
	beq _0804ECBA
	ldr r1, _0804ECCC @ =Particle_DrawList
	ldr r2, _0804ECD0 @ =AuxSprite_DrawList
	ldr r3, _0804ECD4 @ =MainSprite_DrawList
	movs r0, #0
	bl Video_SetDrawPasses
	ldr r0, [r4, #0x2c]
	movs r1, #0
	bl VM_ExecByID
_0804ECBA:
	ldr r0, [r4, #0x1c]
	adds r0, #1
	str r0, [r4, #0x1c]
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804ECC8: .4byte 0x0000FFFF
_0804ECCC: .4byte Particle_DrawList
_0804ECD0: .4byte AuxSprite_DrawList
_0804ECD4: .4byte MainSprite_DrawList
