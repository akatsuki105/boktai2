	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r7, r2
	movs r6, #0
	ldr r2, _0818F5B4 @ =0x00000F36
	adds r0, r7, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _0818F5E4
	movs r0, #1
	mov sb, r0
	adds r5, r1, #0
	ldr r1, _0818F5B8 @ =0x0000077A
	adds r4, r7, r1
_0818F5A4:
	ldrh r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _0818F5BC
	movs r0, #1
	b _0818F5BE
	.align 2, 0
_0818F5B4: .4byte 0x00000F36
_0818F5B8: .4byte 0x0000077A
_0818F5BC:
	movs r0, #0
_0818F5BE:
	cmp r0, #0
	bne _0818F5CE
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
_0818F5CE:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	ldr r1, _0818F5F0 @ =0x00000F36
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _0818F5A4
_0818F5E4:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818F5F0: .4byte 0x00000F36
