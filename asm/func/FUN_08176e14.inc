	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	movs r3, #0
	ldr r0, _08176E44 @ =0x00001012
	adds r2, r1, r0
	movs r4, #0
	ldrsh r0, [r2, r4]
	cmp r3, r0
	bge _08176E66
	movs r5, #1
	adds r6, r2, #0
	ldr r7, _08176E48 @ =0x00000755
	adds r2, r1, r7
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r4, #0x92
	lsls r4, r4, #1
_08176E38:
	ldrb r0, [r2]
	ands r0, r5
	cmp r0, #0
	beq _08176E4C
	movs r0, #1
	b _08176E4E
	.align 2, 0
_08176E44: .4byte 0x00001012
_08176E48: .4byte 0x00000755
_08176E4C:
	movs r0, #0
_08176E4E:
	cmp r0, #0
	bne _08176E58
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
_08176E58:
	adds r2, r2, r4
	adds r1, r1, r4
	adds r3, #1
	movs r7, #0
	ldrsh r0, [r6, r7]
	cmp r3, r0
	blt _08176E38
_08176E66:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
