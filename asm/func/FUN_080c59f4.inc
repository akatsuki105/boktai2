	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	str r1, [sp, #4]
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	ldr r0, _080C5A44 @ =0x000008F8
	add r0, sl
	mov sb, r0
	movs r1, #0
	movs r0, #1
	mov r2, sb
	strb r0, [r2]
	strb r1, [r2, #2]
	strb r1, [r2, #3]
	strb r1, [r2, #1]
	movs r1, #0xdb
	lsls r1, r1, #4
	add r1, sl
	movs r0, #0xbe
	lsls r0, r0, #2
	add r0, sl
	str r0, [r1]
	ldr r1, _080C5A48 @ =FUN_080c52f0
	mov r0, sb
	bl FUN_080c52e0
	movs r7, #0x60
	movs r3, #0
_080C5A36:
	cmp r3, #0xa
	bhi _080C5AAC
	lsls r0, r3, #2
	ldr r1, _080C5A4C @ =_080C5A50
	adds r1, r0, r1
	ldr r1, [r1]
	mov pc, r1
	.align 2, 0
_080C5A44: .4byte 0x000008F8
_080C5A48: .4byte FUN_080c52f0
_080C5A4C: .4byte _080C5A50
_080C5A50: @ jump table
	.4byte _080C5A7C @ case 0
	.4byte _080C5A7C @ case 1
	.4byte _080C5A7C @ case 2
	.4byte _080C5A7C @ case 3
	.4byte _080C5A8C @ case 4
	.4byte _080C5A8C @ case 5
	.4byte _080C5A8C @ case 6
	.4byte _080C5A8C @ case 7
	.4byte _080C5A9C @ case 8
	.4byte _080C5A9C @ case 9
	.4byte _080C5A9C @ case 10
_080C5A7C:
	ldr r2, _080C5A88 @ =0x00008206
	movs r4, #2
	mov r8, r4
	adds r7, #0x50
	movs r1, #0x20
	b _080C5AB8
	.align 2, 0
_080C5A88: .4byte 0x00008206
_080C5A8C:
	ldr r2, _080C5A98 @ =0x00008206
	movs r1, #3
	mov r8, r1
	adds r7, #0x40
	movs r1, #0x28
	b _080C5AB8
	.align 2, 0
_080C5A98: .4byte 0x00008206
_080C5A9C:
	ldr r2, _080C5AA8 @ =0x00008207
	movs r4, #2
	mov r8, r4
	adds r7, #0x20
	movs r1, #0x30
	b _080C5AB8
	.align 2, 0
_080C5AA8: .4byte 0x00008207
_080C5AAC:
	ldr r2, _080C5B60 @ =0x00008207
	movs r0, #3
	mov r8, r0
	adds r7, #0x14
	movs r1, #0x38
	lsls r0, r3, #2
_080C5AB8:
	adds r0, r0, r3
	lsls r0, r0, #4
	adds r0, #8
	mov r4, sb
	adds r6, r4, r0
	adds r5, r6, #0
	adds r5, #0x48
	strh r7, [r5]
	adds r0, r6, #0
	adds r0, #0x4b
	mov r4, r8
	strb r4, [r0]
	adds r0, #1
	strb r1, [r0]
	ldr r1, _080C5B64 @ =0x085AD0DE
	lsls r0, r3, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x4a
	strb r0, [r1]
	ldrb r0, [r1]
	adds r1, #4
	strh r0, [r1]
	adds r4, r6, #0
	adds r4, #0x2c
	adds r0, r4, #0
	adds r1, r2, #0
	str r3, [sp, #0x10]
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #2
	add r0, r8
	strh r0, [r6, #0x10]
	movs r0, #3
	strb r0, [r6, #7]
	ldr r0, _080C5B68 @ =0x0000259C
	add r0, sl
	str r0, [r4, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #2
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	mov r0, sb
	ldrb r1, [r0, #2]
	ldrh r0, [r5]
	adds r2, r0, #0
	muls r2, r1, r2
	adds r0, r2, #0
	ldrh r4, [r6, #0x1c]
	adds r0, r0, r4
	strh r0, [r6, #0x1c]
	ldr r3, [sp, #0x10]
	adds r3, #1
	cmp r3, #0xd
	bgt _080C5B3A
	b _080C5A36
_080C5B3A:
	movs r1, #0x8d
	lsls r1, r1, #3
	add r1, sb
	ldr r0, [sp, #0xc]
	str r0, [sp]
	mov r0, sl
	ldr r2, [sp, #4]
	ldr r3, [sp, #8]
	bl FUN_080c595c
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C5B60: .4byte 0x00008207
_080C5B64: .4byte 0x085AD0DE
_080C5B68: .4byte 0x0000259C
