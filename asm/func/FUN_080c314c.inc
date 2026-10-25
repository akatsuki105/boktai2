	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	ldr r2, _080C31B8 @ =0x00000DB8
	add r2, sb
	movs r3, #0
	movs r0, #1
	strb r0, [r2]
	ldr r0, _080C31BC @ =0x00000DBA
	add r0, sb
	strb r3, [r0]
	ldr r0, _080C31C0 @ =0x00000DBB
	add r0, sb
	strb r3, [r0]
	ldr r0, _080C31C4 @ =0x00000DBE
	add r0, sb
	strh r1, [r0]
	movs r7, #0
	movs r0, #1
	mov sl, r0
	movs r1, #0
	mov r8, r1
_080C317E:
	movs r0, #0x54
	muls r0, r7, r0
	ldr r1, _080C31C8 @ =0x00000DC4
	adds r0, r0, r1
	mov r1, sb
	adds r4, r1, r0
	adds r6, r4, #0
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r0, _080C31CC @ =0x08251E04
	bl HashName
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	mov r1, sl
	ands r0, r1
	cmp r0, #0
	beq _080C31D4
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080C31D0 @ =0x00000201
	bl AuxSprite_Add
	b _080C31DE
	.align 2, 0
_080C31B8: .4byte 0x00000DB8
_080C31BC: .4byte 0x00000DBA
_080C31C0: .4byte 0x00000DBB
_080C31C4: .4byte 0x00000DBE
_080C31C8: .4byte 0x00000DC4
_080C31CC: .4byte 0x08251E04
_080C31D0: .4byte 0x00000201
_080C31D4:
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, _080C3214 @ =0x00000401
	bl AuxSprite_Add
_080C31DE:
	mov r0, r8
	strh r0, [r6, #0x10]
	adds r0, r5, #0
	movs r1, #0xb4
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	mov r1, sl
	strb r1, [r6, #7]
	adds r0, r4, #0
	adds r0, #0x50
	mov r1, r8
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r7, #1
	cmp r7, #0x1f
	ble _080C317E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C3214: .4byte 0x00000401
