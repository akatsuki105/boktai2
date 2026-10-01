	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	bl EntityDA0B_TakeFnChanged
	cmp r0, #0
	beq _0801DD0C
	movs r1, #2
	add r0, sp, #4
	strh r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #1
	add r3, sp, #4
	bl FUN_0801d4dc
	ldr r0, _0801DD68 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #3
	bl FUN_0807c7c8
	ldr r0, _0801DD6C @ =0x000002E1
	bl PlaySound_082406e0
_0801DD0C:
	adds r0, r4, #0
	bl FUN_0801d540
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0823b8ac
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	subs r0, #0x1e
	cmp r0, #0x45
	bhi _0801DD56
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _0801DD56
	ldr r0, _0801DD68 @ =0x03002BE0
	ldr r0, [r0]
	add r3, sp, #8
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldrh r0, [r3]
	adds r0, #0xc8
	strh r0, [r3]
	movs r2, #0x80
	lsls r2, r2, #6
	str r3, [sp]
	movs r0, #2
	movs r1, #0
	movs r3, #0x40
	bl FUN_08015c90
	ldr r0, _0801DD70 @ =0x000001C5
	bl PlaySound_082406e0
_0801DD56:
	ldr r0, [r4, #0x44]
	cmp r0, #0x63
	bls _0801DD78
	ldr r1, _0801DD74 @ =FUN_0801dd84
	adds r0, r4, #0
	bl EntityDA0B_SetFn
	b _0801DD7C
	.align 2, 0
_0801DD68: .4byte 0x03002BE0
_0801DD6C: .4byte 0x000002E1
_0801DD70: .4byte 0x000001C5
_0801DD74: .4byte FUN_0801dd84
_0801DD78:
	adds r0, #1
	str r0, [r4, #0x44]
_0801DD7C:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
