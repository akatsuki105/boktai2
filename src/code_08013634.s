	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08013634
FUN_08013634: @ 0x08013634
	ldr r1, _0801363C @ =0x03000050
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0801363C: .4byte 0x03000050

	thumb_func_start FUN_08013640
FUN_08013640: @ 0x08013640
	push {lr}
	ldrb r2, [r1]
	cmp r2, #0
	beq _0801364E
	movs r0, #1
	rsbs r0, r0, #0
	b _08013662
_0801364E:
	str r2, [r1, #0x38]
	ldr r2, [r0, #0x1c]
	str r2, [r1, #0x3c]
	cmp r2, #0
	beq _0801365A
	str r1, [r2, #0x38]
_0801365A:
	str r1, [r0, #0x1c]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_08013662:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013668
FUN_08013668: @ 0x08013668
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r1, #0x38]
	ldr r2, [r1, #0x3c]
	ldrb r0, [r1]
	cmp r0, #0
	bne _0801367C
	movs r0, #1
	rsbs r0, r0, #0
	b _08013690
_0801367C:
	cmp r3, #0
	beq _08013684
	str r2, [r3, #0x3c]
	b _08013686
_08013684:
	str r2, [r4, #0x1c]
_08013686:
	cmp r2, #0
	beq _0801368C
	str r3, [r2, #0x38]
_0801368C:
	movs r0, #0
	strb r0, [r1]
_08013690:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013698
FUN_08013698: @ 0x08013698
	push {lr}
	ldr r1, [r0, #0xc]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #0xc]
	ldr r1, _080136B0 @ =FUN_080136cc
	str r1, [r0, #0x34]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_080136B0: .4byte FUN_080136cc

	thumb_func_start FUN_080136b4
FUN_080136b4: @ 0x080136B4
	ldr r1, [r0, #0xc]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0xc]
	ldr r1, _080136C4 @ =FUN_080136c8
	str r1, [r0, #0x34]
	bx lr
	.align 2, 0
_080136C4: .4byte FUN_080136c8

	thumb_func_start FUN_080136c8
FUN_080136c8: @ 0x080136C8
	bx lr
	.align 2, 0

	thumb_func_start FUN_080136cc
FUN_080136cc: @ 0x080136CC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r6, r3, #0
	adds r6, #0xc
	adds r5, r3, #0
	adds r5, #0x24
	ldr r4, [r3, #8]
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080136FE
	cmp r1, #0
	blt _080136FE
	ldr r0, _08013704 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080136FE
	ldr r0, _08013708 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0801370C
_080136FE:
	movs r7, #0
	b _0801371A
	.align 2, 0
_08013704: .4byte 0x030046A8
_08013708: .4byte 0x030046AC
_0801370C:
	ldr r0, _0801372C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r7, r0, r2
_0801371A:
	ldrb r1, [r3, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08013730
	ldrh r0, [r4, #2]
	strh r0, [r5, #2]
	b _0801376E
	.align 2, 0
_0801372C: .4byte 0x030046A4
_08013730:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013740
	adds r0, #4
	b _0801374C
_08013740:
	ldr r0, _08013760 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0801374C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08013764
	cmp r2, #2
	beq _08013768
	b _0801376C
	.align 2, 0
_08013760: .4byte 0x030046A4
_08013764:
	ldrb r0, [r4, #4]
	b _0801376A
_08013768:
	ldrb r0, [r4]
_0801376A:
	subs r1, r1, r0
_0801376C:
	strh r1, [r5, #2]
_0801376E:
	movs r1, #2
	ldrsh r0, [r4, r1]
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	blt _080137A4
	cmp r1, #0
	beq _080137A4
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0801378E
	adds r0, #4
	b _0801379A
_0801378E:
	ldr r0, _080137B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r7, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0801379A:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _080137B4
_080137A4:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	b _080137C6
	.align 2, 0
_080137B0: .4byte 0x030046A4
_080137B4:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldrh r0, [r4]
	strh r0, [r5]
	ldrh r0, [r4, #4]
	strh r0, [r5, #4]
_080137C6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080137cc
FUN_080137cc: @ 0x080137CC
	push {r4, lr}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	beq _080137E2
_080137D4:
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r4, [r4, #0x3c]
	cmp r4, #0
	bne _080137D4
_080137E2:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080137ec
FUN_080137ec: @ 0x080137EC
	ldr r1, _080137F4 @ =0x03000050
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080137F4: .4byte 0x03000050

	thumb_func_start FUN_080137f8
FUN_080137f8: @ 0x080137F8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08013814 @ =0x03000050
	str r4, [r0]
	movs r0, #0
	str r0, [r4, #0x1c]
	ldr r0, _08013818 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x18]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08013814: .4byte 0x03000050
_08013818: .4byte 0x00001C1A

	thumb_func_start CreateNPC_0801381c
CreateNPC_0801381c: @ 0x0801381C
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013854
	ldr r1, _0801384C @ =FUN_080137cc
	ldr r2, _08013850 @ =FUN_080137ec
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080137f8
	cmp r0, #0
	bge _08013854
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013856
	.align 2, 0
_0801384C: .4byte FUN_080137cc
_08013850: .4byte FUN_080137ec
_08013854:
	adds r0, r4, #0
_08013856:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801385c
FUN_0801385c: @ 0x0801385C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r0, _08013880 @ =0x03000050
	ldr r0, [r0]
	cmp r0, #0
	bne _08013884
	movs r0, #0
	movs r1, #0
	bl CreateNPC_0801381c
	cmp r0, #0
	bne _08013884
	movs r0, #1
	rsbs r0, r0, #0
	b _080138EE
	.align 2, 0
_08013880: .4byte 0x03000050
_08013884:
	movs r0, #0
	strb r0, [r6]
	str r5, [r6, #8]
	strb r4, [r6, #1]
	strb r0, [r6, #2]
	strh r0, [r6, #4]
	strh r0, [r6, #6]
	lsls r0, r4, #0x18
	cmp r0, #0
	bne _080138A0
	ldr r0, _0801389C @ =FUN_080136cc
	b _080138A2
	.align 2, 0
_0801389C: .4byte FUN_080136cc
_080138A0:
	ldr r0, _080138F4 @ =FUN_080136c8
_080138A2:
	str r0, [r6, #0x34]
	adds r4, r6, #0
	adds r4, #0xc
	ldr r5, _080138F8 @ =0x03000050
	ldr r0, [r5]
	ldr r1, [r0, #0x18]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	ldr r0, [r5]
	ldr r3, [r0, #0x18]
	ldrb r2, [r6, #0x16]
	lsrs r2, r2, #3
	ldrb r1, [r6, #0x17]
	lsrs r1, r1, #3
	muls r2, r1, r2
	lsls r1, r2, #4
	adds r1, r1, r2
	lsls r1, r1, #1
	ldrh r3, [r3, #4]
	adds r1, r1, r3
	strh r1, [r6, #0x14]
	movs r1, #0xfc
	strb r1, [r6, #0x1c]
	movs r1, #2
	strb r1, [r6, #0x1b]
	adds r1, r6, #0
	bl FUN_08013640
	movs r0, #0
_080138EE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080138F4: .4byte FUN_080136c8
_080138F8: .4byte 0x03000050

	thumb_func_start FUN_080138fc
FUN_080138fc: @ 0x080138FC
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc
	bl FUN_0822dabc
	ldr r0, _0801391C @ =0x03000050
	ldr r0, [r0]
	cmp r0, #0
	beq _08013914
	adds r1, r4, #0
	bl FUN_08013668
_08013914:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801391C: .4byte 0x03000050

	thumb_func_start FUN_08013920
FUN_08013920: @ 0x08013920
	ldr r1, _08013928 @ =0x03000054
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08013928: .4byte 0x03000054

	thumb_func_start FUN_0801392c
FUN_0801392c: @ 0x0801392C
	push {lr}
	ldrb r2, [r1]
	cmp r2, #0
	beq _0801393A
	movs r0, #1
	rsbs r0, r0, #0
	b _0801394E
_0801393A:
	str r2, [r1, #0x64]
	ldr r2, [r0, #0x1c]
	str r2, [r1, #0x68]
	cmp r2, #0
	beq _08013946
	str r1, [r2, #0x64]
_08013946:
	str r1, [r0, #0x1c]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0801394E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013954
FUN_08013954: @ 0x08013954
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r1, #0x64]
	ldr r2, [r1, #0x68]
	ldrb r0, [r1]
	cmp r0, #0
	bne _08013968
	movs r0, #1
	rsbs r0, r0, #0
	b _0801397C
_08013968:
	cmp r3, #0
	beq _08013970
	str r2, [r3, #0x68]
	b _08013972
_08013970:
	str r2, [r4, #0x1c]
_08013972:
	cmp r2, #0
	beq _08013978
	str r3, [r2, #0x64]
_08013978:
	movs r0, #0
	strb r0, [r1]
_0801397C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013984
FUN_08013984: @ 0x08013984
	push {lr}
	ldr r1, [r0, #0xc]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #0xc]
	ldr r1, _0801399C @ =FUN_080139b8
	str r1, [r0, #0x60]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_0801399C: .4byte FUN_080139b8

	thumb_func_start FUN_080139a0
FUN_080139a0: @ 0x080139A0
	ldr r1, [r0, #0xc]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0xc]
	ldr r1, _080139B0 @ =FUN_080139b4
	str r1, [r0, #0x60]
	bx lr
	.align 2, 0
_080139B0: .4byte FUN_080139b4

	thumb_func_start FUN_080139b4
FUN_080139b4: @ 0x080139B4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080139b8
FUN_080139b8: @ 0x080139B8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #8]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080139E2
	cmp r1, #0
	blt _080139E2
	ldr r0, _080139E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080139E2
	ldr r0, _080139EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080139F0
_080139E2:
	movs r0, #0
	b _080139FE
	.align 2, 0
_080139E8: .4byte 0x030046A8
_080139EC: .4byte 0x030046AC
_080139F0:
	ldr r0, _08013A18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080139FE:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r2, [r4, #8]
	ldrh r0, [r2]
	strh r0, [r4, #0x28]
	ldrb r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08013A1C
	ldrh r0, [r2, #2]
	strh r0, [r4, #0x2a]
	b _08013A5E
	.align 2, 0
_08013A18: .4byte 0x030046A4
_08013A1C:
	adds r5, r2, #0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013A2E
	adds r0, #4
	b _08013A3A
_08013A2E:
	ldr r0, _08013A50 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08013A3A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08013A54
	cmp r2, #2
	beq _08013A58
	b _08013A5C
	.align 2, 0
_08013A50: .4byte 0x030046A4
_08013A54:
	ldrb r0, [r5, #4]
	b _08013A5A
_08013A58:
	ldrb r0, [r5]
_08013A5A:
	subs r1, r1, r0
_08013A5C:
	strh r1, [r4, #0x2a]
_08013A5E:
	ldr r1, [r4, #8]
	ldrh r0, [r1, #4]
	strh r0, [r4, #0x2c]
	movs r0, #2
	ldrsh r1, [r1, r0]
	movs r2, #0x2a
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r1, #0
	bgt _08013A7C
	adds r0, r4, #0
	adds r0, #0x56
	ldrb r1, [r0]
	subs r0, #2
	b _08013AA6
_08013A7C:
	adds r0, r4, #0
	adds r0, #0x5a
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	bge _08013A92
	adds r2, r4, #0
	adds r2, #0x56
	adds r0, r4, #0
	adds r0, #0x5e
	b _08013AB4
_08013A92:
	adds r0, r4, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _08013AAC
	adds r0, r4, #0
	adds r0, #0x55
	ldrb r1, [r0]
	subs r0, #1
_08013AA6:
	strb r1, [r0]
	adds r1, r0, #0
	b _08013AC2
_08013AAC:
	adds r2, r4, #0
	adds r2, #0x56
	adds r0, r4, #0
	adds r0, #0x5c
_08013AB4:
	ldrh r0, [r0]
	asrs r1, r0
	ldrb r0, [r2]
	subs r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x54
	strb r0, [r1]
_08013AC2:
	adds r2, r1, #0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bgt _08013AD0
	movs r0, #1
	strb r0, [r2]
_08013AD0:
	ldrb r0, [r1]
	strb r0, [r4, #0x14]
	ldrb r0, [r1]
	strb r0, [r4, #0x15]
	ldr r0, [r4, #8]
	movs r1, #2
	ldrsh r0, [r0, r1]
	movs r2, #0x2a
	ldrsh r1, [r4, r2]
	cmp r0, r1
	blt _08013B10
	cmp r1, #0
	beq _08013B10
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08013AFA
	adds r0, #4
	b _08013B06
_08013AFA:
	ldr r0, _08013B18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08013B06:
	ldrh r0, [r0, #2]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08013B1C
_08013B10:
	ldr r0, [r4, #0xc]
	movs r1, #1
	orrs r0, r1
	b _08013B24
	.align 2, 0
_08013B18: .4byte 0x030046A4
_08013B1C:
	ldr r0, [r4, #0xc]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08013B24:
	str r0, [r4, #0xc]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08013b2c
FUN_08013b2c: @ 0x08013B2C
	push {r4, lr}
	ldr r4, [r0, #0x1c]
	cmp r4, #0
	beq _08013B42
_08013B34:
	ldr r1, [r4, #0x60]
	adds r0, r4, #0
	bl _call_via_r1
	ldr r4, [r4, #0x68]
	cmp r4, #0
	bne _08013B34
_08013B42:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08013b4c
FUN_08013b4c: @ 0x08013B4C
	ldr r1, _08013B54 @ =0x03000054
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08013B54: .4byte 0x03000054

	thumb_func_start FUN_08013b58
FUN_08013b58: @ 0x08013B58
	ldr r1, _08013B64 @ =0x03000054
	str r0, [r1]
	movs r1, #0
	str r1, [r0, #0x1c]
	movs r0, #0
	bx lr
	.align 2, 0
_08013B64: .4byte 0x03000054

	thumb_func_start FUN_08013b68
FUN_08013b68: @ 0x08013B68
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #9
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08013BA0
	ldr r1, _08013B98 @ =FUN_08013b2c
	ldr r2, _08013B9C @ =FUN_08013b4c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08013b58
	cmp r0, #0
	bge _08013BA0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08013BA2
	.align 2, 0
_08013B98: .4byte FUN_08013b2c
_08013B9C: .4byte FUN_08013b4c
_08013BA0:
	adds r0, r4, #0
_08013BA2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08013ba8
FUN_08013ba8: @ 0x08013BA8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	mov r8, r3
	ldr r0, _08013BD4 @ =0x03000054
	ldr r7, [r0]
	cmp r7, #0
	bne _08013BD8
	movs r0, #0
	movs r1, #0
	bl FUN_08013b68
	adds r7, r0, #0
	cmp r7, #0
	bne _08013BD8
	movs r0, #1
	rsbs r0, r0, #0
	b _08013C58
	.align 2, 0
_08013BD4: .4byte 0x03000054
_08013BD8:
	movs r1, #0
	strb r1, [r6]
	str r4, [r6, #8]
	ldr r0, [sp, #0x30]
	strb r0, [r6, #1]
	strb r1, [r6, #2]
	strh r1, [r6, #4]
	strh r1, [r6, #6]
	adds r0, r6, #0
	adds r0, #0x54
	strb r5, [r0]
	adds r0, #1
	mov r1, r8
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x56
	ldr r0, [sp, #0x18]
	strb r0, [r1]
	adds r1, #1
	ldr r0, [sp, #0x1c]
	strb r0, [r1]
	adds r1, #1
	ldr r0, [sp, #0x20]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x24]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x2c]
	strh r0, [r1]
	ldrb r0, [r6, #1]
	cmp r0, #0
	bne _08013C28
	ldr r0, _08013C24 @ =FUN_080139b8
	b _08013C2A
	.align 2, 0
_08013C24: .4byte FUN_080139b8
_08013C28:
	ldr r0, _08013C64 @ =FUN_080139b4
_08013C2A:
	str r0, [r6, #0x60]
	adds r5, r6, #0
	adds r5, #0x38
	ldr r1, _08013C68 @ =0x00001C1B
	adds r0, r5, #0
	bl Video_GetActorSprite
	adds r4, r6, #0
	adds r4, #0xc
	ldr r2, _08013C6C @ =0x00000202
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0822a470
	movs r0, #5
	strh r0, [r4, #0x10]
	movs r0, #2
	strb r0, [r6, #0x13]
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_0801392c
	movs r0, #0
_08013C58:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08013C64: .4byte FUN_080139b4
_08013C68: .4byte 0x00001C1B
_08013C6C: .4byte 0x00000202

	thumb_func_start FUN_08013c70
FUN_08013c70: @ 0x08013C70
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0xc
	bl FUN_0822a4e0
	ldr r0, _08013C90 @ =0x03000054
	ldr r0, [r0]
	cmp r0, #0
	beq _08013C88
	adds r1, r4, #0
	bl FUN_08013954
_08013C88:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08013C90: .4byte 0x03000054

