	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _080618A8 @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldrh r0, [r3, #0x1e]
	adds r0, #0xbe
	strh r0, [r3, #0x1e]
	ldr r2, _080618AC @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080618B0
	asrs r1, r0, #0xc
	b _080618B6
	.align 2, 0
_080618A8: .4byte 0x000006AC
_080618AC: .4byte 0x085B0A08
_080618B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080618B6:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080618D2
	asrs r1, r0, #0xc
	b _080618D8
_080618D2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080618D8:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080618FC
	asrs r1, r0, #0xc
	b _08061902
_080618FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08061902:
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r4, r7
	strh r1, [r0]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _08061920
	asrs r2, r0, #0xc
	b _08061926
_08061920:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08061926:
	ldr r3, _08061964 @ =0x0000070C
	adds r0, r4, r3
	strh r2, [r0]
	add r2, sp, #8
	adds r0, r6, #0
	add r1, sp, #4
	bl FUN_080617dc
	ldr r7, _08061968 @ =0x000006F4
	adds r0, r4, r7
	ldr r2, _0806196C @ =0x00000704
	adds r1, r4, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	adds r0, r4, #0
	bl FUN_0806181c
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08061964: .4byte 0x0000070C
_08061968: .4byte 0x000006F4
_0806196C: .4byte 0x00000704
