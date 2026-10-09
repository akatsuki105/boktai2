	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _08096B6C @ =0x000015C4
	adds r5, r6, r0
	ldr r1, _08096B70 @ =0x000015CC
	adds r4, r6, r1
_08096B52:
	ldr r1, _08096B74 @ =0x00003FE0
	adds r0, r6, r1
	adds r2, r0, r7
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bge _08096B78
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _08096BA2
	.align 2, 0
_08096B6C: .4byte 0x000015C4
_08096B70: .4byte 0x000015CC
_08096B74: .4byte 0x00003FE0
_08096B78:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	adds r2, #0x43
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r6, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r5, #0
	ldr r1, _08096BB4 @ =0x000002DF
	bl MainSprite_SetPltt
_08096BA2:
	adds r5, #0x60
	adds r4, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _08096B52
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08096BB4: .4byte 0x000002DF
