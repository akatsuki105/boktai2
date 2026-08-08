	push {lr}
	adds r2, r0, #0
	cmp r1, #6
	bls _080E81E6
	b _080E835A
_080E81E6:
	lsls r0, r1, #2
	ldr r1, _080E81F0 @ =_080E81F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080E81F0: .4byte _080E81F4
_080E81F4: @ jump table
	.4byte _080E8334 @ case 0
	.4byte _080E8270 @ case 1
	.4byte _080E8210 @ case 2
	.4byte _080E823E @ case 3
	.4byte _080E82B6 @ case 4
	.4byte _080E82E0 @ case 5
	.4byte _080E8308 @ case 6
_080E8210:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E8234
	cmp r0, #3
	bgt _080E822E
	cmp r0, #1
	ble _080E8226
	b _080E835A
_080E8226:
	cmp r0, #0
	bge _080E822C
	b _080E835A
_080E822C:
	b _080E8234
_080E822E:
	cmp r0, #5
	beq _080E8234
	b _080E835A
_080E8234:
	movs r0, #0xc4
	lsls r0, r0, #1
	bl PlaySound_0824078c
	b _080E835A
_080E823E:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E8262
	cmp r0, #3
	bgt _080E825C
	cmp r0, #1
	ble _080E8254
	b _080E835A
_080E8254:
	cmp r0, #0
	bge _080E825A
	b _080E835A
_080E825A:
	b _080E8262
_080E825C:
	cmp r0, #5
	beq _080E8262
	b _080E835A
_080E8262:
	ldr r0, _080E826C @ =0x00000187
	bl PlaySound_0824078c
	b _080E835A
	.align 2, 0
_080E826C: .4byte 0x00000187
_080E8270:
	ldr r1, _080E8284 @ =0x0000048C
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080E8288
	movs r0, #1
	b _080E828A
	.align 2, 0
_080E8284: .4byte 0x0000048C
_080E8288:
	movs r0, #0
_080E828A:
	cmp r0, #0
	bne _080E835A
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E82AC
	cmp r0, #3
	bgt _080E82A8
	cmp r0, #1
	bgt _080E835A
	cmp r0, #0
	blt _080E835A
	b _080E82AC
_080E82A8:
	cmp r0, #5
	bne _080E835A
_080E82AC:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E835A
_080E82B6:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E82D4
	cmp r0, #3
	bgt _080E82D0
	cmp r0, #1
	bgt _080E835A
	cmp r0, #0
	blt _080E835A
	b _080E82D4
_080E82D0:
	cmp r0, #5
	bne _080E835A
_080E82D4:
	ldr r0, _080E82DC @ =0x00000189
	bl PlaySound_082406e0
	b _080E835A
	.align 2, 0
_080E82DC: .4byte 0x00000189
_080E82E0:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E82FE
	cmp r0, #3
	bgt _080E82FA
	cmp r0, #1
	bgt _080E835A
	cmp r0, #0
	blt _080E835A
	b _080E82FE
_080E82FA:
	cmp r0, #5
	bne _080E835A
_080E82FE:
	movs r0, #0xc5
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080E835A
_080E8308:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E8326
	cmp r0, #3
	bgt _080E8322
	cmp r0, #1
	bgt _080E835A
	cmp r0, #0
	blt _080E835A
	b _080E8326
_080E8322:
	cmp r0, #5
	bne _080E835A
_080E8326:
	ldr r0, _080E8330 @ =0x0000018B
	bl PlaySound_082406e0
	b _080E835A
	.align 2, 0
_080E8330: .4byte 0x0000018B
_080E8334:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #3
	beq _080E8352
	cmp r0, #3
	bgt _080E834E
	cmp r0, #1
	bgt _080E835A
	cmp r0, #0
	blt _080E835A
	b _080E8352
_080E834E:
	cmp r0, #5
	bne _080E835A
_080E8352:
	movs r0, #0xc7
	lsls r0, r0, #1
	bl PlaySound_0824078c
_080E835A:
	pop {r0}
	bx r0
	.align 2, 0
