	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r2, [r0]
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, #5
	bne _080980C2
	b _080981FE
_080980C2:
	ldr r7, _08098138 @ =0x00003AEE
	adds r5, r3, r7
	ldr r0, _0809813C @ =0x00003AEB
	adds r4, r3, r0
	ldrb r0, [r5]
	ldrb r1, [r4]
	cmp r0, r1
	bne _080981A4
	movs r4, #1
	rsbs r4, r4, #0
	adds r6, r4, #0
	movs r2, #0
	ldr r1, _08098140 @ =0x030046A0
	mov ip, r1
	ldr r1, [r1]
	ldr r7, _08098144 @ =0x00003FF0
	adds r0, r3, r7
	ldrb r5, [r5]
	adds r0, r0, r5
	movs r5, #0
	ldrsb r5, [r0, r5]
	adds r1, #0x68
_080980EE:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r5
	bne _080980F8
	adds r6, r2, #0
_080980F8:
	cmp r4, #0
	bge _08098102
	cmp r0, #0
	bge _08098102
	adds r4, r2, #0
_08098102:
	adds r1, #2
	adds r2, #1
	cmp r2, #3
	ble _080980EE
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r3, r1
	ldr r0, [r0]
	ldr r2, _08098148 @ =0x00000285
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08098160
	mov r7, ip
	ldr r0, [r7]
	adds r0, #0x5a
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r6, r0
	beq _080981FE
	cmp r6, #0
	blt _0809814C
	adds r1, r6, #0
	adds r1, #0x10
	ldr r2, _0809813C @ =0x00003AEB
	adds r0, r3, r2
	b _0809816C
	.align 2, 0
_08098138: .4byte 0x00003AEE
_0809813C: .4byte 0x00003AEB
_08098140: .4byte 0x030046A0
_08098144: .4byte 0x00003FF0
_08098148: .4byte 0x00000285
_0809814C:
	cmp r4, #0
	blt _080981FE
	adds r1, r4, #0
	adds r1, #0x10
	ldr r6, _0809815C @ =0x00003AEB
	adds r0, r3, r6
	strb r1, [r0]
	b _08098202
	.align 2, 0
_0809815C: .4byte 0x00003AEB
_08098160:
	cmp r6, #0
	blt _08098178
	adds r1, r6, #0
	adds r1, #0x10
	ldr r7, _08098174 @ =0x00003AEB
	adds r0, r3, r7
_0809816C:
	strb r1, [r0]
	movs r0, #4
	b _08098204
	.align 2, 0
_08098174: .4byte 0x00003AEB
_08098178:
	cmp r4, #0
	blt _0809818C
	adds r1, r4, #0
	adds r1, #0x10
	ldr r2, _08098188 @ =0x00003AEB
	adds r0, r3, r2
	strb r1, [r0]
	b _08098202
	.align 2, 0
_08098188: .4byte 0x00003AEB
_0809818C:
	mov r6, ip
	ldr r0, [r6]
	adds r0, #0x5a
	ldrb r0, [r0]
	adds r0, #0x10
	ldr r7, _080981A0 @ =0x00003AEB
	adds r1, r3, r7
	strb r0, [r1]
	b _08098202
	.align 2, 0
_080981A0: .4byte 0x00003AEB
_080981A4:
	ldr r6, _080981E4 @ =0x00000285
	adds r0, r2, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080981FA
	ldr r0, _080981E8 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5a
	movs r7, #0
	ldrsh r2, [r1, r7]
	lsls r1, r2, #1
	adds r1, r1, r0
	adds r1, #0x68
	ldr r6, _080981EC @ =0x00003FF0
	adds r0, r3, r6
	ldrb r5, [r5]
	adds r0, r0, r5
	movs r7, #0
	ldrsh r1, [r1, r7]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	bne _080981F0
	ldrb r1, [r4]
	adds r0, r2, #0
	adds r0, #0x10
	cmp r1, r0
	beq _08098202
	b _080981FE
	.align 2, 0
_080981E4: .4byte 0x00000285
_080981E8: .4byte 0x030046A0
_080981EC: .4byte 0x00003FF0
_080981F0:
	ldrb r1, [r4]
	adds r0, r2, #0
	adds r0, #0x10
	cmp r1, r0
	beq _080981FE
_080981FA:
	cmp r1, #0xf
	bhi _08098202
_080981FE:
	movs r0, #0
	b _08098204
_08098202:
	movs r0, #1
_08098204:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
