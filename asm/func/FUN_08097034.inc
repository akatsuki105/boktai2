	push {r4, r5, r6, lr}
	adds r4, r0, #0
	bl FUN_0808c548
	ldr r5, _08097084 @ =0x030044E0
	ldrh r1, [r5]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08097090
	ldr r0, _08097088 @ =0x000009F8
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808c700
	ldr r1, _0809708C @ =0x00001444
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
	b _080971B2
	.align 2, 0
_08097084: .4byte 0x030044E0
_08097088: .4byte 0x000009F8
_0809708C: .4byte 0x00001444
_08097090:
	ldr r2, _08097134 @ =0x000009F8
	adds r0, r4, r2
	strb r1, [r0]
	ldr r1, _08097138 @ =0x00001444
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
	bl FUN_08096d90
	ldrh r1, [r5, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _0809718C
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _0809713C @ =0x00003AE8
	adds r0, r4, r2
	bl FUN_0808fbbc
	ldr r0, _08097140 @ =0x000014AC
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08097144 @ =0x000014C4
	adds r0, r4, r1
	ldr r2, _08097148 @ =0x00003AEE
	adds r5, r4, r2
	ldrb r1, [r5]
	bl FUN_08096af0
	ldr r1, _0809714C @ =0x00003AEB
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _0809715C
	ldr r2, _08097150 @ =0x0000144C
	adds r1, r4, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08097154 @ =0x0000204C
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
	ldr r1, _08097158 @ =FUN_08097530
	b _0809717E
	.align 2, 0
_08097134: .4byte 0x000009F8
_08097138: .4byte 0x00001444
_0809713C: .4byte 0x00003AE8
_08097140: .4byte 0x000014AC
_08097144: .4byte 0x000014C4
_08097148: .4byte 0x00003AEE
_0809714C: .4byte 0x00003AEB
_08097150: .4byte 0x0000144C
_08097154: .4byte 0x0000204C
_08097158: .4byte FUN_08097530
_0809715C:
	ldrb r1, [r5]
	adds r0, r4, #0
	bl FUN_08096d40
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08096630
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08096bb8
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08096d90
	ldr r1, _08097188 @ =FUN_080971c4
_0809717E:
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
	b _080971B2
	.align 2, 0
_08097188: .4byte FUN_080971c4
_0809718C:
	ldr r1, _080971B8 @ =0x00003AE8
	adds r0, r4, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _080971B2
	ldr r2, _080971BC @ =0x00001464
	adds r0, r4, r2
	ldr r2, _080971C0 @ =0x00003AEB
	adds r1, r4, r2
	ldrb r1, [r1]
	bl FUN_08096af0
	adds r0, r4, #0
	bl FUN_08096a34
	adds r0, r4, #0
	bl FUN_080967c0
_080971B2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080971B8: .4byte 0x00003AE8
_080971BC: .4byte 0x00001464
_080971C0: .4byte 0x00003AEB
