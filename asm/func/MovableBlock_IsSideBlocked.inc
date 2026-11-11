	push {r4, r5, lr}
	adds r5, r0, #0
	adds r5, #0xbc
	movs r0, #0
	cmp r2, #1
	beq _08003130
	cmp r2, #1
	bgt _08003112
	cmp r2, #0
	beq _0800311C
	b _08003148
_08003112:
	cmp r2, #2
	beq _08003134
	cmp r2, #3
	beq _08003144
	b _08003148
_0800311C:
	ldr r0, _0800312C @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	rsbs r0, r0, #0
	b _08003148
	.align 2, 0
_0800312C: .4byte 0x030046A4
_08003130:
	movs r0, #1
	b _08003148
_08003134:
	ldr r0, _08003140 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	b _08003148
	.align 2, 0
_08003140: .4byte 0x030046A4
_08003144:
	movs r0, #1
	rsbs r0, r0, #0
_08003148:
	adds r4, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0800315A
	adds r4, r0, #4
	b _08003166
_0800315A:
	ldr r0, _0800318C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r4, r1, r0
_08003166:
	cmp r4, #0
	beq _0800319E
	ldrb r3, [r4]
	lsrs r0, r3, #4
	cmp r0, #0
	bne _08003190
	movs r0, #0xf
	ldrb r2, [r5]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	blo _0800319E
	ldrh r1, [r4, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800319E
	b _080031A2
	.align 2, 0
_0800318C: .4byte 0x030046A4
_08003190:
	movs r0, #0xf
	ldrb r2, [r5]
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bhs _080031A2
_0800319E:
	movs r0, #0
	b _080031A4
_080031A2:
	movs r0, #1
_080031A4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
