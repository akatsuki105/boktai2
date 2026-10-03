	push {r4, r5, r6, lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r0, _0809C0E8 @ =0x0300013C
	ldr r4, [r0]
	cmp r4, #0
	bne _0809C09C
	b _0809C1A0
_0809C09C:
	ldr r0, _0809C0EC @ =0x000009FE
	adds r5, r4, r0
	strb r1, [r5]
	ldr r2, _0809C0F0 @ =0x000009FC
	adds r0, r4, r2
	ldrh r6, [r0]
	cmp r6, #0
	bne _0809C1A0
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bne _0809C104
	adds r0, r4, #0
	bl FUN_0808d39c
	ldr r0, _0809C0F4 @ =0x00000A3C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C0F8 @ =0x00000AA8
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C0FC @ =0x00000B08
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _0809C100 @ =0x00000A31
	adds r0, r4, r1
	strb r6, [r0]
	movs r0, #0
	bl ClearBGTilemapBuffer
	b _0809C198
	.align 2, 0
_0809C0E8: .4byte 0x0300013C
_0809C0EC: .4byte 0x000009FE
_0809C0F0: .4byte 0x000009FC
_0809C0F4: .4byte 0x00000A3C
_0809C0F8: .4byte 0x00000AA8
_0809C0FC: .4byte 0x00000B08
_0809C100: .4byte 0x00000A31
_0809C104:
	cmp r0, #2
	bhi _0809C14C
	ldr r0, _0809C140 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #5
	ands r0, r1
	cmp r0, #0
	bne _0809C11C
	adds r0, r4, #0
	bl FUN_0808d3d4
_0809C11C:
	ldr r1, [r4, #0x18]
	movs r0, #0
	movs r2, #0
	bl Video_SetBGLayer
	ldrb r0, [r5]
	cmp r0, #1
	bne _0809C18A
	ldr r0, _0809C144 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0xae
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r1, [r0]
	ldr r2, _0809C148 @ =0x00000A1E
	adds r0, r4, r2
	strh r1, [r0]
	b _0809C18A
	.align 2, 0
_0809C140: .4byte 0x030047A4
_0809C144: .4byte 0x030046A0
_0809C148: .4byte 0x00000A1E
_0809C14C:
	adds r0, r4, #0
	bl FUN_0808d39c
	ldr r0, _0809C1A8 @ =0x00000A3C
	adds r1, r4, r0
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C1AC @ =0x00000AA8
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809C1B0 @ =0x00000B08
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, [r4, #0x18]
	ldrb r2, [r5]
	subs r2, #2
	movs r0, #0
	bl Video_SetBGLayer
	ldr r0, _0809C1B4 @ =0x0000EFDA
	bl TextBox_SetBgPltt
	ldr r1, _0809C1B8 @ =0x00000A31
	adds r0, r4, r1
	strb r6, [r0]
_0809C18A:
	movs r0, #0
	str r0, [sp]
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
_0809C198:
	ldr r2, _0809C1BC @ =0x00000A24
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_0809C1A0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809C1A8: .4byte 0x00000A3C
_0809C1AC: .4byte 0x00000AA8
_0809C1B0: .4byte 0x00000B08
_0809C1B4: .4byte 0x0000EFDA
_0809C1B8: .4byte 0x00000A31
_0809C1BC: .4byte 0x00000A24
