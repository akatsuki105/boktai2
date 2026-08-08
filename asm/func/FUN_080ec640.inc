	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_080ef840
	adds r6, r0, #0
	cmp r6, #0
	beq _080EC69A
	ldr r0, _080EC668 @ =0x03002C60
	ldr r7, [r0]
	movs r1, #4
	ldr r0, _080EC66C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080EC670 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080EC674
	movs r0, #1
	b _080EC676
	.align 2, 0
_080EC668: .4byte 0x03002C60
_080EC66C: .4byte 0x030046A0
_080EC670: .4byte 0x00000934
_080EC674:
	movs r0, #0
_080EC676:
	cmp r0, #0
	beq _080EC68A
	ldr r0, _080EC6A0 @ =0x03002B28
	ldrh r0, [r0]
	ldrh r1, [r5]
	bl FUN_080ec5f0
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080EC69A
_080EC68A:
	ldrh r0, [r6, #0x32]
	cmp r0, #0x13
	bhi _080EC69A
	ldrh r0, [r5]
	bl FUN_080edda0
	cmp r0, #0
	beq _080EC6A4
_080EC69A:
	movs r0, #0
	b _080EC6EC
	.align 2, 0
_080EC6A0: .4byte 0x03002B28
_080EC6A4:
	movs r0, #8
	bl Malloc
	adds r4, r0, #0
	movs r1, #8
	bl ClearMemory
	str r5, [r4, #4]
	str r7, [r4]
	ldr r0, _080EC6F4 @ =0x03002C60
	str r4, [r0]
	ldr r1, _080EC6F8 @ =0x000001DF
	adds r0, r5, r1
	ldrb r0, [r0]
	bl FUN_080ec900
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080EC6DC
	adds r0, r5, #0
	bl FUN_08002a48
_080EC6DC:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_080eca74
	ldrh r0, [r6, #0x32]
	adds r0, #1
	strh r0, [r6, #0x32]
	movs r0, #1
_080EC6EC:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080EC6F4: .4byte 0x03002C60
_080EC6F8: .4byte 0x000001DF
