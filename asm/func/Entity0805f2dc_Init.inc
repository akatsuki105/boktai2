	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	str r1, [r6, #0x50]
	cmp r1, #0x3b
	bhi _0805F260
	movs r0, #0x3c
	str r0, [r6, #0x50]
_0805F260:
	adds r7, r6, #0
	adds r7, #0x18
	movs r0, #0x34
	adds r0, r0, r6
	mov r8, r0
	movs r0, #0x54
	adds r0, r0, r6
	mov sb, r0
	adds r5, r7, #0
	movs r4, #1
_0805F274:
	adds r0, r5, #0
	ldr r1, _0805F2B8 @ =0x00005AFE
	bl Video_GetAuxSprite
	adds r5, #0x1c
	subs r4, #1
	cmp r4, #0
	bge _0805F274
	adds r0, r7, #0
	movs r1, #9
	bl Video_SetAuxSpritePltt
	mov r0, r8
	movs r1, #0x11
	bl Video_SetAuxSpritePltt
	mov r5, sb
	movs r4, #0
_0805F298:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl Entity0805f2dc_InitElem
	adds r4, #1
	adds r5, #0x94
	cmp r4, #0xb
	ble _0805F298
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F2B8: .4byte 0x00005AFE
