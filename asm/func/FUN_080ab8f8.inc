	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	adds r4, r7, #0
	adds r4, #0xc0
	ldrb r0, [r7, #0x18]
	cmp r0, #0
	bne _080AB916
	movs r6, #0
	movs r0, #0x63
	mov r8, r0
	b _080AB91C
_080AB916:
	movs r6, #1
	movs r2, #0x62
	mov r8, r2
_080AB91C:
	adds r5, r4, #0
	adds r5, #0x2c
	ldr r1, _080AB990 @ =0x00000BA8
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r6, [r4, #0x10]
	movs r0, #3
	strb r0, [r4, #7]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x20]
	adds r0, #0x18
	strh r0, [r4, #0x20]
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080AB994 @ =0x03003584
	mov r2, r8
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r4, #0x48]
	ldr r3, _080AB998 @ =0x00003DEF
	adds r2, r4, #0
	adds r2, #0x4c
	adds r6, r4, #0
	adds r6, #0x6c
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x6a
_080AB96E:
	strh r3, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080AB96E
	mov r0, r8
	strh r0, [r5, #6]
	str r2, [r5, #0xc]
	str r7, [r4, #0x74]
	movs r0, #1
	strb r0, [r6]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB990: .4byte 0x00000BA8
_080AB994: .4byte 0x03003584
_080AB998: .4byte 0x00003DEF
