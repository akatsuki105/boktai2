	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08143144 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143148
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814314A
	.align 2, 0
_08143144: .4byte 0x0000046D
_08143148:
	movs r0, #0
_0814314A:
	cmp r0, #0
	beq _081431CE
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r2, [r0]
	ldr r1, _0814317C @ =0x0000025D
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08143188
	ldr r1, _08143180 @ =0x000004B7
	adds r0, r4, r1
	strb r2, [r0]
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, _08143184 @ =0x0000046E
	adds r6, r4, r0
	b _081431CA
	.align 2, 0
_0814317C: .4byte 0x0000025D
_08143180: .4byte 0x000004B7
_08143184: .4byte 0x0000046E
_08143188:
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	ldr r1, _081431D8 @ =0x000004B7
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081431DC @ =0x0000046E
	adds r6, r4, r0
	cmp r1, r2
	bne _081431AE
	ldrb r0, [r6]
	cmp r0, #0
	bne _081431AE
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081431CE
_081431AE:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl MainSprite_SetAnim
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
_081431CA:
	movs r0, #0
	strb r0, [r6]
_081431CE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081431D8: .4byte 0x000004B7
_081431DC: .4byte 0x0000046E
