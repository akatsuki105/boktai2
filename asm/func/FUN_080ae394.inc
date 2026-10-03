	push {r4, r5, r6, lr}
	sub sp, #0x18
	adds r4, r0, #0
	ldr r0, _080AE40C @ =0x0000C091
	ldr r1, _080AE410 @ =0x0000AD57
	bl GetFile
	ldr r2, _080AE414 @ =0x000004DC
	adds r1, r4, r2
	str r0, [r1]
	mov r2, sp
	adds r1, r0, #0
	ldm r1!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r1!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldr r1, [sp, #0xc]
	adds r1, r1, r0
	str r1, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, r1, r0
	str r1, [sp, #0x10]
	ldr r1, [sp, #0x14]
	adds r1, r1, r0
	str r1, [sp, #0x14]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r2, _080AE418 @ =0x03003E78
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r0, #3
	movs r1, #1
	bl SetBGPrioDirect
	ldr r0, _080AE41C @ =0x000092B3
	ldr r1, _080AE420 @ =0x0000E2BA
	bl GetFile
	movs r2, #0x9c
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r0, r3
	str r0, [r1]
	movs r1, #5
	ldr r5, _080AE424 @ =0x000004E4
	adds r4, r4, r5
	movs r0, #3
_080AE3F8:
	strb r1, [r4, #4]
	strb r1, [r4]
	adds r4, #1
	subs r0, #1
	cmp r0, #0
	bge _080AE3F8
	add sp, #0x18
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AE40C: .4byte 0x0000C091
_080AE410: .4byte 0x0000AD57
_080AE414: .4byte 0x000004DC
_080AE418: .4byte 0x03003E78
_080AE41C: .4byte 0x000092B3
_080AE420: .4byte 0x0000E2BA
_080AE424: .4byte 0x000004E4
