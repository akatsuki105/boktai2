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
	ldr r2, _08136760 @ =0x00000B3A
	adds r0, r7, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _08136790
	movs r0, #1
	mov sb, r0
	adds r5, r1, #0
	ldr r1, _08136764 @ =0x00000755
	adds r4, r7, r1
_08136750:
	ldrb r0, [r4]
	mov r2, sb
	ands r0, r2
	cmp r0, #0
	beq _08136768
	movs r0, #1
	b _0813676A
	.align 2, 0
_08136760: .4byte 0x00000B3A
_08136764: .4byte 0x00000755
_08136768:
	movs r0, #0
_0813676A:
	cmp r0, #0
	bne _0813677A
	adds r0, r5, #0
	mov r1, r8
	movs r2, #0xa
	movs r3, #0x1e
	bl Sprite_UpdateVanishBlink
_0813677A:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	ldr r1, _0813679C @ =0x00000B3A
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _08136750
_08136790:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813679C: .4byte 0x00000B3A
