	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r7, r4, #0
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _08025D32
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r0, #0x8e
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r4, #0
	bl Boss_PlayAnim
_08025D32:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025E02
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08025E02
	movs r3, #0x9f
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r3, #4
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08025D6E
	rsbs r1, r1, #0
_08025D6E:
	cmp r1, #0x20
	ble _08025D8A
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	movs r3, #0x20
	rsbs r3, r3, #0
	adds r2, r3, #0
	cmp r1, r0
	bge _08025D86
	movs r2, #0x20
_08025D86:
	strh r2, [r6, #0x14]
	b _08025D92
_08025D8A:
	ldrh r0, [r5, #4]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6, #0x14]
_08025D92:
	movs r0, #0x9e
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r3, #0
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08025DA8
	rsbs r1, r1, #0
_08025DA8:
	cmp r1, #0x20
	ble _08025DC4
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #0x20
	rsbs r3, r3, #0
	adds r2, r3, #0
	cmp r1, r0
	bge _08025DC0
	movs r2, #0x20
_08025DC0:
	strh r2, [r6, #0x10]
	b _08025DCC
_08025DC4:
	ldrh r0, [r5]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6, #0x10]
_08025DCC:
	movs r0, #0xac
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	movs r3, #0xc8
	lsls r3, r3, #5
	cmp r0, r3
	bhi _08025DE2
	adds r0, #0x40
	strh r0, [r1]
	b _08025E02
_08025DE2:
	movs r2, #0
	strh r3, [r1]
	ldr r1, _08025E0C @ =FUN_08025e10
	movs r0, #7
	adds r3, r4, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r2, [r0]
	adds r1, r4, #0
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
_08025E02:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08025E0C: .4byte FUN_08025e10
