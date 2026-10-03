	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	bl FUN_0808c548
	ldr r5, _080940C0 @ =0x030044E0
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _080940CC
	ldr r0, _080940C4 @ =0x000009F8
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _080940C8 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a5b0
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a5e0
	b _080941EC
	.align 2, 0
_080940C0: .4byte 0x030044E0
_080940C4: .4byte 0x000009F8
_080940C8: .4byte 0x00001444
_080940CC:
	ldr r2, _08094170 @ =0x000009F8
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08094174 @ =0x00001444
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r4, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08092608
	ldrh r1, [r5, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _080941CC
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _08094178 @ =0x00003AE8
	adds r7, r4, r2
	adds r0, r7, #0
	bl FUN_0808fbbc
	ldr r0, _0809417C @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08094180 @ =0x000014C4
	adds r0, r4, r1
	ldr r2, _08094184 @ =0x00003AEE
	adds r5, r4, r2
	ldrb r1, [r5]
	bl FUN_080921e8
	ldr r1, _08094188 @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08094198
	ldr r2, _0809418C @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08094190 @ =0x0000204C
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, [r4, #0x58]
	movs r1, #4
	movs r2, #0
	bl FUN_0808c510
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0808b6fc
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _08094194 @ =FUN_080944f4
	b _080941BA
	.align 2, 0
_08094170: .4byte 0x000009F8
_08094174: .4byte 0x00001444
_08094178: .4byte 0x00003AE8
_0809417C: .4byte 0x000014AC
_08094180: .4byte 0x000014C4
_08094184: .4byte 0x00003AEE
_08094188: .4byte 0x00003AEB
_0809418C: .4byte 0x0000144C
_08094190: .4byte 0x0000204C
_08094194: .4byte FUN_080944f4
_08094198:
	ldr r1, _080941C4 @ =0x00003F9C
	adds r0, r4, r1
	ldrb r0, [r0]
	ldrb r1, [r5]
	bl GetItemID
	bl FUN_080925d4
	adds r1, r0, #0
	adds r0, r7, #0
	bl FUN_080916d0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08092608
	ldr r1, _080941C8 @ =FUN_08094200
_080941BA:
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080941EC
	.align 2, 0
_080941C4: .4byte 0x00003F9C
_080941C8: .4byte FUN_08094200
_080941CC:
	ldr r2, _080941F4 @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fb68
	cmp r0, #0
	beq _080941EC
	ldr r1, _080941F8 @ =0x00001464
	adds r0, r4, r1
	ldr r2, _080941FC @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_080921e8
	adds r0, r4, #0
	bl FUN_08092070
_080941EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080941F4: .4byte 0x00003AE8
_080941F8: .4byte 0x00001464
_080941FC: .4byte 0x00003AEB
