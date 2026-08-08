	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08073064 @ =0x0000037D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #1
	beq _080730CC
	cmp r0, #1
	bgt _08073068
	cmp r0, #0
	beq _08073072
	b _0807316E
	.align 2, 0
_08073064: .4byte 0x0000037D
_08073068:
	cmp r0, #2
	beq _080730E2
	cmp r0, #3
	beq _0807310C
	b _0807316E
_08073072:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0807316E
	movs r0, #0xcb
	bl PlaySound_082406e0
	ldr r2, _080730AC @ =0x000004A6
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080730B0
	movs r0, #1
	b _080730B2
	.align 2, 0
_080730AC: .4byte 0x000004A6
_080730B0:
	movs r0, #2
_080730B2:
	strb r0, [r5]
	ldr r1, _080730C4 @ =0x000004A6
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	ldr r2, _080730C8 @ =0x0000037E
	adds r0, r4, r2
	strh r1, [r0]
	b _0807316E
	.align 2, 0
_080730C4: .4byte 0x000004A6
_080730C8: .4byte 0x0000037E
_080730CC:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	b _080730F6
_080730E2:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xa
_080730F6:
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	bl FUN_080726b4
	b _0807316E
_0807310C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	cmp r0, #0
	beq _0807316E
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	cmp r1, #4
	bls _08073154
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08073150 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _08073160
	.align 2, 0
_08073150: .4byte 0x000002E7
_08073154:
	ldr r2, _08073174 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08073178 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_08073160:
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_08072620
	adds r0, r4, #0
	bl FUN_080726b4
_0807316E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08073174: .4byte 0x000002E6
_08073178: .4byte 0x000002E7
