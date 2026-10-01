	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0809E160 @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E164 @ =0x00000942
	adds r0, r2, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _0809E186
	movs r1, #2
	ldr r4, _0809E168 @ =0x00000934
	adds r0, r2, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E16C
	movs r0, #1
	b _0809E16E
	.align 2, 0
_0809E160: .4byte 0x030046A0
_0809E164: .4byte 0x00000942
_0809E168: .4byte 0x00000934
_0809E16C:
	movs r0, #0
_0809E16E:
	cmp r0, #0
	bne _0809E190
	ldr r0, _0809E18C @ =0x03000140
	ldr r0, [r0]
	cmp r0, #0
	beq _0809E186
	adds r0, r3, #0
	adds r0, #0x2c
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E190
_0809E186:
	movs r0, #0
	b _0809E192
	.align 2, 0
_0809E18C: .4byte 0x03000140
_0809E190:
	movs r0, #1
_0809E192:
	pop {r4}
	pop {r1}
	bx r1
