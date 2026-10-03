	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080926F0 @ =0x00003F9C
	adds r5, r4, r0
	ldrb r0, [r5]
	ldr r1, _080926F4 @ =0x00003AEE
	adds r6, r4, r1
	ldrb r1, [r6]
	bl GetItemID
	cmp r0, #0
	bge _080926FC
	ldrb r0, [r5]
	ldr r2, _080926F8 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl GetItemID
	cmp r0, #0
	bge _0809273C
	b _08092738
	.align 2, 0
_080926F0: .4byte 0x00003F9C
_080926F4: .4byte 0x00003AEE
_080926F8: .4byte 0x00003AEB
_080926FC:
	ldr r0, _0809270C @ =0x00003AEB
	adds r2, r4, r0
	ldrb r1, [r2]
	cmp r1, #0x14
	bne _08092710
	movs r0, #2
	b _0809273E
	.align 2, 0
_0809270C: .4byte 0x00003AEB
_08092710:
	cmp r1, #0x10
	bne _08092718
	movs r0, #1
	b _0809273E
_08092718:
	ldrb r0, [r6]
	cmp r0, r1
	bne _0809273C
	ldr r1, _08092734 @ =0x00003AE8
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08092738
	movs r0, #0x10
	strb r0, [r2]
	movs r0, #1
	b _0809273E
	.align 2, 0
_08092734: .4byte 0x00003AE8
_08092738:
	movs r0, #0
	b _0809273E
_0809273C:
	movs r0, #3
_0809273E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
