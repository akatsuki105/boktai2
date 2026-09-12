	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _08090760 @ =0x0000402C
	adds r0, r4, r1
	ldr r2, [r0]
	movs r5, #1
	rsbs r5, r5, #0
	ldr r0, _08090764 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _0809076C
	ldr r0, _08090768 @ =0x0000403C
_08090740:
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq _080907CA
	adds r5, r0, #0
	lsls r0, r5, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	adds r1, r0, #0
	cmp r1, #0
	bne _080907B2
	b _080907C4
	.align 2, 0
_08090760: .4byte 0x0000402C
_08090764: .4byte 0x030044E0
_08090768: .4byte 0x0000403C
_0809076C:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _0809077C
	ldr r0, _08090778 @ =0x0000403D
	b _08090740
	.align 2, 0
_08090778: .4byte 0x0000403D
_0809077C:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0809078C
	ldr r0, _08090788 @ =0x0000403E
	b _08090740
	.align 2, 0
_08090788: .4byte 0x0000403E
_0809078C:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080907CA
	ldr r0, _080907BC @ =0x0000403F
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r5
	beq _080907CA
	adds r5, r0, #0
	lsls r0, r5, #4
	adds r0, r0, r2
	ldrb r0, [r0]
	bl FUN_0808fd2c
	adds r1, r0, #0
	cmp r1, #0
	beq _080907C4
_080907B2:
	ldr r2, _080907C0 @ =0x00004039
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _080907CA
	.align 2, 0
_080907BC: .4byte 0x0000403F
_080907C0: .4byte 0x00004039
_080907C4:
	ldr r2, _080907D4 @ =0x00004039
	adds r0, r4, r2
	strb r1, [r0]
_080907CA:
	cmp r5, #0
	bge _080907D8
	movs r0, #0
	b _080907E6
	.align 2, 0
_080907D4: .4byte 0x00004039
_080907D8:
	ldr r1, _080907EC @ =0x00004038
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_080906c8
	movs r0, #1
_080907E6:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080907EC: .4byte 0x00004038
