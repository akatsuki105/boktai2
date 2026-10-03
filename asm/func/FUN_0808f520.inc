	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _0808F538 @ =0x000009EC
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _0808F53C
	lsls r0, r0, #2
	movs r1, #0
	bl FUN_0808a458
	b _0808F544
	.align 2, 0
_0808F538: .4byte 0x000009EC
_0808F53C:
	movs r0, #0x40
	movs r1, #0
	bl FUN_0808a458
_0808F544:
	ldr r1, _0808F5E0 @ =0x000009EC
	adds r5, r4, r1
	ldrh r0, [r5]
	cmp r0, #0x10
	bne _0808F556
	movs r0, #0xb0
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0808F556:
	ldr r1, _0808F5E4 @ =0x000034E4
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0xc0
	bl MainSprite_AdvanceAnim
	ldrh r0, [r5]
	cmp r0, #0x68
	bls _0808F572
	ldr r0, _0808F5E8 @ =0x00003504
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #5
	strh r0, [r1]
_0808F572:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x74
	bls _0808F5DA
	movs r0, #7
	bl TextBox_ShowLine
	ldr r0, _0808F5E8 @ =0x00003504
	adds r1, r4, r0
	ldr r0, _0808F5EC @ =0x0000FFE4
	strh r0, [r1]
	ldr r0, _0808F5F0 @ =0x0000360C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, _0808F5F4 @ =0x0000354C
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _0808F5C4
	ldr r0, _0808F5F8 @ =0x000035AC
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0808F5C4:
	ldr r1, _0808F5FC @ =0x0000401C
	adds r0, r4, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_0808f1bc
	ldr r1, _0808F600 @ =FUN_0808f670
	adds r0, r4, #0
	bl FUN_0808a33c
_0808F5DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808F5E0: .4byte 0x000009EC
_0808F5E4: .4byte 0x000034E4
_0808F5E8: .4byte 0x00003504
_0808F5EC: .4byte 0x0000FFE4
_0808F5F0: .4byte 0x0000360C
_0808F5F4: .4byte 0x0000354C
_0808F5F8: .4byte 0x000035AC
_0808F5FC: .4byte 0x0000401C
_0808F600: .4byte FUN_0808f670
