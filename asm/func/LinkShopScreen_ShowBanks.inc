	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	movs r1, #4
	ldr r2, _081E32F4 @ =0x00001610
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081E32F8
	movs r0, #1
	b _081E32FA
	.align 2, 0
_081E32F4: .4byte 0x00001610
_081E32F8:
	movs r0, #0
_081E32FA:
	cmp r0, #0
	bne _081E3300
	b _081E3422
_081E3300:
	movs r6, #0
	ldr r0, _081E3430 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x91
	lsls r3, r3, #4
	adds r0, r0, r3
	movs r1, #0
	ldrsh r4, [r0, r1]
	movs r2, #0
	ldr r0, _081E3434 @ =0x000003E7
	adds r7, r5, #0
	adds r7, #0xe8
	movs r3, #0x88
	adds r3, r3, r5
	mov r8, r3
	movs r1, #0x28
	adds r1, r1, r5
	mov sb, r1
	cmp r4, r0
	ble _081E3332
	ldr r1, _081E3438 @ =0xFFFFFC18
_081E332A:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E332A
_081E3332:
	movs r3, #0xa4
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0x63
	ble _081E3352
_081E334A:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E334A
_081E3352:
	ldr r0, _081E343C @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r7, #0
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #9
	ble _081E336E
_081E3366:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3366
_081E336E:
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, r8
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E338A
_081E3382:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3382
_081E338A:
	ldr r0, _081E343C @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r0, sb
	bl MainSprite_LoadPose
	ldr r1, _081E3440 @ =0x00000BB6
	adds r0, r5, r1
	ldrh r4, [r0]
	adds r2, r6, #0
	ldr r0, _081E3434 @ =0x000003E7
	cmp r4, r0
	ble _081E33B0
	ldr r1, _081E3438 @ =0xFFFFFC18
_081E33A8:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E33A8
_081E33B0:
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0x63
	ble _081E33D0
_081E33C8:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E33C8
_081E33D0:
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #9
	ble _081E33F0
_081E33E8:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E33E8
_081E33F0:
	movs r1, #0x82
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	adds r2, r6, #0
	cmp r4, #0
	ble _081E3410
_081E3408:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E3408
_081E3410:
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, _081E343C @ =0x00000AA8
	adds r1, r5, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
_081E3422:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3430: .4byte 0x030046A0
_081E3434: .4byte 0x000003E7
_081E3438: .4byte 0xFFFFFC18
_081E343C: .4byte 0x00000AA8
_081E3440: .4byte 0x00000BB6
