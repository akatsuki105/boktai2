	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0809E0FC @ =0x030046A0
	ldr r2, [r0]
	ldr r1, _0809E100 @ =0x00000942
	adds r0, r2, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _0809E124
	movs r1, #2
	ldr r5, _0809E104 @ =0x00000934
	adds r0, r2, r5
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809E108
	movs r0, #1
	b _0809E10A
	.align 2, 0
_0809E0FC: .4byte 0x030046A0
_0809E100: .4byte 0x00000942
_0809E104: .4byte 0x00000934
_0809E108:
	movs r0, #0
_0809E10A:
	cmp r0, #0
	bne _0809E12C
	adds r0, r3, #0
	bl FUN_0809e05c
	cmp r0, #0
	bge _0809E12C
	ldr r0, _0809E128 @ =0x03000140
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809E12C
_0809E124:
	movs r0, #0
	b _0809E132
	.align 2, 0
_0809E128: .4byte 0x03000140
_0809E12C:
	adds r0, r4, #0
	bl FUN_0809e034
_0809E132:
	pop {r4, r5}
	pop {r1}
	bx r1
