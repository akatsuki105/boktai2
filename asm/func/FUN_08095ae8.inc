	push {r4, r5, r6, lr}
	adds r5, r0, #0
	bl FUN_0808c548
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #3
	bl FUN_0808a610
	adds r0, r5, #0
	movs r1, #1
	movs r2, #5
	movs r3, #4
	bl FUN_0808a768
	ldr r6, _08095B28 @ =0x030044E0
	ldrh r1, [r6]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08095B30
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #9
	bl FUN_0808c658
	ldr r1, _08095B2C @ =FUN_08095c60
	b _08095C12
	.align 2, 0
_08095B28: .4byte 0x030044E0
_08095B2C: .4byte FUN_08095c60
_08095B30:
	ldr r2, _08095BC4 @ =0x000009F8
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08095BC8 @ =0x00001444
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x60
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	ldr r2, _08095BCC @ =0x00001E64
	adds r0, r5, r2
	adds r1, r4, #0
	movs r2, #0x40
	movs r3, #1
	bl MainSprite_SetPose
	ldrh r1, [r6, #2]
	movs r6, #1
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	beq _08095C20
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _08095BD0 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fbbc
	ldr r0, _08095BD4 @ =0x000014AC
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _08095BD8 @ =0x000014C4
	adds r0, r5, r1
	ldr r2, _08095BDC @ =0x00003AEE
	adds r4, r5, r2
	ldrb r1, [r4]
	bl FUN_080952f4
	ldr r1, _08095BE0 @ =0x00003AEB
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08095BF0
	ldr r2, _08095BE4 @ =0x0000144C
	adds r1, r5, r2
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, _08095BE8 @ =0x0000204C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r6
	str r0, [r1]
	ldr r0, [r5, #0x58]
	movs r1, #4
	movs r2, #0
	bl FUN_0808c510
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0808b6fc
	adds r0, r5, #0
	bl FUN_0808c700
	ldr r1, _08095BEC @ =FUN_080960c8
	b _08095C12
	.align 2, 0
_08095BC4: .4byte 0x000009F8
_08095BC8: .4byte 0x00001444
_08095BCC: .4byte 0x00001E64
_08095BD0: .4byte 0x00003AE8
_08095BD4: .4byte 0x000014AC
_08095BD8: .4byte 0x000014C4
_08095BDC: .4byte 0x00003AEE
_08095BE0: .4byte 0x00003AEB
_08095BE4: .4byte 0x0000144C
_08095BE8: .4byte 0x0000204C
_08095BEC: .4byte FUN_080960c8
_08095BF0:
	ldrb r1, [r4]
	adds r0, r5, #0
	bl GetWeaponPermission
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_08094a94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080954a8
	adds r0, r5, #0
	movs r1, #1
	bl weapon_08095820
	ldr r1, _08095C1C @ =weapon_08095d4c
_08095C12:
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0808a354
	b _08095C4E
	.align 2, 0
_08095C1C: .4byte weapon_08095d4c
_08095C20:
	ldr r1, _08095C54 @ =0x00003AE8
	adds r0, r5, r1
	bl FUN_0808fb68
	cmp r0, #0
	beq _08095C4E
	ldr r2, _08095C58 @ =0x00001464
	adds r0, r5, r2
	ldr r2, _08095C5C @ =0x00003AEB
	adds r1, r5, r2
	ldrb r1, [r1]
	bl FUN_080952f4
	adds r0, r5, #0
	bl FUN_08094eb0
	adds r0, r5, #0
	bl weapon_08094f88
	adds r0, r5, #0
	movs r1, #0
	bl weapon_08095820
_08095C4E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08095C54: .4byte 0x00003AE8
_08095C58: .4byte 0x00001464
_08095C5C: .4byte 0x00003AEB
