	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081fa608
FUN_081fa608: @ 0x081FA608
	ldr r1, _081FA618 @ =gDvalinn
	ldr r2, [r1]
	ldr r1, _081FA61C @ =0x000007DC
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
	bx lr
	.align 2, 0
_081FA618: .4byte gDvalinn
_081FA61C: .4byte 0x000007DC

	thumb_func_start FUN_081fa620
FUN_081fa620: @ 0x081FA620
	ldr r0, _081FA624 @ =0x00000231
	bx lr
	.align 2, 0
_081FA624: .4byte 0x00000231

	thumb_func_start FUN_081fa628
FUN_081fa628: @ 0x081FA628
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	adds r6, r0, #0
	adds r5, r1, #0
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FA654 @ =0x05000002
	bl CpuSet
	cmp r5, #0
	beq _081FA658
	cmp r5, #1
	bne _081FA652
	b _081FA800
_081FA652:
	b _081FABA4
	.align 2, 0
_081FA654: .4byte 0x05000002
_081FA658:
	adds r0, r6, #0
	adds r0, #0x4d
	add r3, sp, #0x44
	ldrb r4, [r0]
	ldr r5, _081FA680 @ =0xFFFFFF00
	ldr r2, _081FA684 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FA688
	asrs r1, r0, #0xc
	b _081FA68E
	.align 2, 0
_081FA680: .4byte 0xFFFFFF00
_081FA684: .4byte 0x085B0A08
_081FA688:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FA68E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081FA6A8 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FA6AC
	asrs r0, r0, #0xc
	b _081FA6B2
	.align 2, 0
_081FA6A8: .4byte 0x085B0A08
_081FA6AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA6B2:
	strh r0, [r3, #4]
	adds r2, r6, #0
	adds r2, #0x50
	add r1, sp, #0x44
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r5, #0x46
	add r5, sp
	ldrh r0, [r5]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r1, [r2, #4]
	add r6, sp, #0x48
	ldrh r6, [r6]
	adds r1, r1, r6
	add r0, sp, #0x48
	strh r1, [r0]
	add r5, sp, #0x44
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081FA6FE
	cmp r1, #0
	blt _081FA6FE
	ldr r0, _081FA704 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FA6FE
	ldr r0, _081FA708 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FA70C
_081FA6FE:
	movs r4, #0
	b _081FA71A
	.align 2, 0
_081FA704: .4byte 0x030046A8
_081FA708: .4byte 0x030046AC
_081FA70C:
	ldr r0, _081FA72C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FA71A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FA730
	adds r0, #4
	b _081FA73C
	.align 2, 0
_081FA72C: .4byte 0x030046A4
_081FA730:
	ldr r0, _081FA7E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FA73C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r1, #0xff
	mov sl, r1
	ldr r2, _081FA7E8 @ =0x085B0A08
	mov sb, r2
	add r7, sp, #0x4c
	movs r3, #0
	mov r8, r3
	movs r6, #0
_081FA756:
	ldr r5, _081FA7EC @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _081FA7F0 @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _081FA7F4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r2, sl
	ands r1, r2
	add r0, sp, #0x44
	movs r5, #0
	ldrsh r3, [r0, r5]
	lsls r0, r1, #1
	add r0, sb
	movs r2, #0
	ldrsh r4, [r0, r2]
	add r0, sp, #0x44
	movs r2, #2
	ldrsh r5, [r0, r2]
	mov ip, r5
	movs r5, #4
	ldrsh r2, [r0, r5]
	adds r1, #0x40
	mov r0, sl
	ands r1, r0
	lsls r1, r1, #1
	add r1, sb
	movs r5, #0
	ldrsh r0, [r1, r5]
	adds r3, r3, r4
	adds r2, r2, r0
	add r0, sp, #0x4c
	strh r3, [r0]
	mov r0, ip
	strh r0, [r7, #2]
	strh r2, [r7, #4]
	movs r0, #3
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	movs r0, #0xda
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r6, [sp, #0x14]
	str r6, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r6, [sp, #0x20]
	str r6, [sp, #0x24]
	str r6, [sp, #0x28]
	str r6, [sp, #0x2c]
	str r6, [sp, #0x30]
	str r6, [sp, #0x34]
	adds r0, r7, #0
	add r1, sp, #0x3c
	ldr r2, _081FA7F8 @ =0x00002E78
	ldr r3, _081FA7FC @ =0x000038E2
	bl FUN_081f22c0
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	bge _081FA756
	b _081FABA4
	.align 2, 0
_081FA7E4: .4byte 0x030046A4
_081FA7E8: .4byte 0x085B0A08
_081FA7EC: .4byte 0x030046B8
_081FA7F0: .4byte 0x000003FF
_081FA7F4: .4byte 0x0203B400
_081FA7F8: .4byte 0x00002E78
_081FA7FC: .4byte 0x000038E2
_081FA800:
	adds r3, r6, #0
	adds r3, #0x4d
	add r4, sp, #0x44
	ldrb r5, [r3]
	movs r7, #0x1e
	rsbs r7, r7, #0
	ldr r2, _081FA82C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	str r3, [sp, #0x54]
	cmp r0, #0
	blt _081FA830
	asrs r1, r0, #0xc
	b _081FA836
	.align 2, 0
_081FA82C: .4byte 0x085B0A08
_081FA830:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FA836:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081FA850 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _081FA854
	asrs r0, r0, #0xc
	b _081FA85A
	.align 2, 0
_081FA850: .4byte 0x085B0A08
_081FA854:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA85A:
	strh r0, [r4, #4]
	adds r2, r6, #0
	adds r2, #0x50
	add r1, sp, #0x44
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r5, #0x46
	add r5, sp
	ldrh r0, [r5]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r1, [r2, #4]
	add r6, sp, #0x48
	ldrh r6, [r6]
	adds r1, r1, r6
	add r0, sp, #0x48
	strh r1, [r0]
	add r5, sp, #0x44
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r2, [sp, #0x58]
	cmp r3, #0
	blt _081FA8A8
	cmp r1, #0
	blt _081FA8A8
	ldr r0, _081FA8AC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081FA8A8
	ldr r0, _081FA8B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FA8B4
_081FA8A8:
	movs r4, #0
	b _081FA8C2
	.align 2, 0
_081FA8AC: .4byte 0x030046A8
_081FA8B0: .4byte 0x030046AC
_081FA8B4:
	ldr r0, _081FA8D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081FA8C2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FA8D8
	adds r0, #4
	b _081FA8E4
	.align 2, 0
_081FA8D4: .4byte 0x030046A4
_081FA8D8:
	ldr r0, _081FA934 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FA8E4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r1, #0
	mov r8, r1
	mov r2, sp
	adds r2, #0x4c
	str r2, [sp, #0x5c]
	ldr r3, _081FA938 @ =0x085B0A08
	mov sl, r3
	adds r7, r2, #0
	movs r4, #0
	ldr r5, _081FA93C @ =0x030046B8
	mov sb, r5
_081FA904:
	mov r6, sb
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _081FA940 @ =0x000003FF
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _081FA944 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, r8
	lsls r2, r3, #6
	movs r0, #0xf
	ands r1, r0
	adds r2, r2, r1
	lsls r0, r2, #1
	add r0, sl
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #8
	cmp r0, #0
	blt _081FA948
	asrs r0, r0, #0xc
	b _081FA94E
	.align 2, 0
_081FA934: .4byte 0x030046A4
_081FA938: .4byte 0x085B0A08
_081FA93C: .4byte 0x030046B8
_081FA940: .4byte 0x000003FF
_081FA944: .4byte 0x0203B400
_081FA948:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA94E:
	adds r5, r0, #0
	add r0, sp, #0x44
	movs r6, #0
	ldrsh r3, [r0, r6]
	movs r6, #2
	ldrsh r1, [r0, r6]
	mov ip, r1
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x80
	lsls r2, r2, #1
	muls r0, r2, r0
	cmp r0, #0
	blt _081FA97A
	asrs r0, r0, #0xc
	b _081FA980
_081FA97A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FA980:
	add r2, sp, #0x48
	movs r6, #0
	ldrsh r1, [r2, r6]
	adds r2, r3, r5
	adds r1, r1, r0
	add r0, sp, #0x4c
	strh r2, [r0]
	mov r3, ip
	strh r3, [r7, #2]
	strh r1, [r7, #4]
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FA9F4 @ =0x00000237
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r7, #0
	add r1, sp, #0x3c
	ldr r2, _081FA9F8 @ =0x0000F422
	ldr r3, _081FA9FC @ =0x0000121B
	bl FUN_081f22c0
	movs r5, #1
	add r8, r5
	mov r6, r8
	cmp r6, #3
	ble _081FA904
	add r4, sp, #0x44
	ldr r0, [sp, #0x54]
	ldrb r3, [r0]
	ldr r5, _081FAA00 @ =0xFFFFFED4
	ldr r2, _081FAA04 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FAA08
	asrs r1, r0, #0xc
	b _081FAA0E
	.align 2, 0
_081FA9F4: .4byte 0x00000237
_081FA9F8: .4byte 0x0000F422
_081FA9FC: .4byte 0x0000121B
_081FAA00: .4byte 0xFFFFFED4
_081FAA04: .4byte 0x085B0A08
_081FAA08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAA0E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081FAA28 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FAA2C
	asrs r0, r0, #0xc
	b _081FAA32
	.align 2, 0
_081FAA28: .4byte 0x085B0A08
_081FAA2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAA32:
	strh r0, [r4, #4]
	add r1, sp, #0x44
	ldr r3, [sp, #0x58]
	ldrh r0, [r3]
	ldrh r5, [r1]
	adds r0, r0, r5
	strh r0, [r1]
	movs r6, #0x46
	add r6, sp
	ldrh r0, [r6]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r3, #4]
	add r0, sp, #0x48
	ldrh r0, [r0]
	adds r1, r1, r0
	add r2, sp, #0x48
	strh r1, [r2]
	add r5, sp, #0x44
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081FAA7C
	cmp r1, #0
	blt _081FAA7C
	ldr r0, _081FAA80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FAA7C
	ldr r0, _081FAA84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FAA88
_081FAA7C:
	movs r4, #0
	b _081FAA96
	.align 2, 0
_081FAA80: .4byte 0x030046A8
_081FAA84: .4byte 0x030046AC
_081FAA88:
	ldr r0, _081FAAA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FAA96:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FAAAC
	adds r0, #4
	b _081FAAB8
	.align 2, 0
_081FAAA8: .4byte 0x030046A4
_081FAAAC:
	ldr r0, _081FAB08 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FAAB8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r3, #0
	mov r8, r3
	ldr r5, _081FAB0C @ =0x085B0A08
	mov sl, r5
	ldr r7, [sp, #0x5c]
	movs r4, #0
	ldr r6, _081FAB10 @ =0x030046B8
	mov sb, r6
_081FAAD2:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _081FAB14 @ =0x000003FF
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081FAB18 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	mov r5, r8
	lsls r2, r5, #6
	movs r0, #0x1f
	ands r1, r0
	adds r2, r2, r1
	ldr r1, _081FAB0C @ =0x085B0A08
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	lsls r0, r0, #8
	cmp r0, #0
	blt _081FAB1C
	asrs r0, r0, #0xc
	b _081FAB22
	.align 2, 0
_081FAB08: .4byte 0x030046A4
_081FAB0C: .4byte 0x085B0A08
_081FAB10: .4byte 0x030046B8
_081FAB14: .4byte 0x000003FF
_081FAB18: .4byte 0x0203B400
_081FAB1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAB22:
	adds r5, r0, #0
	add r1, sp, #0x44
	movs r0, #0
	ldrsh r3, [r1, r0]
	adds r0, r1, #0
	movs r1, #2
	ldrsh r6, [r0, r1]
	mov ip, r6
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	movs r6, #0x80
	lsls r6, r6, #1
	muls r0, r6, r0
	cmp r0, #0
	blt _081FAB50
	asrs r0, r0, #0xc
	b _081FAB56
_081FAB50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAB56:
	add r6, sp, #0x48
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r2, r3, r5
	adds r1, r1, r0
	add r0, sp, #0x4c
	strh r2, [r0]
	mov r0, ip
	strh r0, [r7, #2]
	strh r1, [r7, #4]
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FABB4 @ =0x00000237
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r7, #0
	add r1, sp, #0x3c
	ldr r2, _081FABB8 @ =0x0000F422
	ldr r3, _081FABBC @ =0x0000121B
	bl FUN_081f22c0
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #3
	ble _081FAAD2
_081FABA4:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FABB4: .4byte 0x00000237
_081FABB8: .4byte 0x0000F422
_081FABBC: .4byte 0x0000121B

	thumb_func_start FUN_081fabc0
FUN_081fabc0: @ 0x081FABC0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x4c
	adds r7, r0, #0
	mov r8, r1
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FAC10 @ =0x05000002
	bl CpuSet
	adds r0, r7, #0
	adds r0, #0x4d
	add r3, sp, #0x44
	ldrb r5, [r0]
	movs r0, #0x5a
	rsbs r0, r0, #0
	mov ip, r0
	ldr r2, _081FAC14 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	mov sb, r4
	adds r6, r3, #0
	cmp r0, #0
	blt _081FAC18
	asrs r1, r0, #0xc
	b _081FAC1E
	.align 2, 0
_081FAC10: .4byte 0x05000002
_081FAC14: .4byte 0x085B0A08
_081FAC18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAC1E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081FAC40 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	adds r5, r1, #0
	cmp r0, #0
	blt _081FAC44
	asrs r0, r0, #0xc
	b _081FAC4A
	.align 2, 0
_081FAC40: .4byte 0x085B0A08
_081FAC44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FAC4A:
	strh r0, [r3, #4]
	adds r2, r7, #0
	adds r2, #0x50
	add r1, sp, #0x44
	ldrh r0, [r2]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r2, _081FAC94 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FAC98 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FAC9C @ =0x0203B400
	adds r0, r0, r2
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FACA0
	asrs r1, r0, #0xc
	b _081FACA6
	.align 2, 0
_081FAC94: .4byte 0x030046B8
_081FAC98: .4byte 0x000003FF
_081FAC9C: .4byte 0x0203B400
_081FACA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FACA6:
	ldrh r0, [r6]
	adds r0, r0, r1
	add r1, sp, #0x44
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _081FACCC
	asrs r1, r0, #0xc
	b _081FACD2
_081FACCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FACD2:
	ldrh r0, [r6, #4]
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r6, #4]
	ldr r0, _081FAD1C @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081FAD2C
	ldr r2, _081FAD20 @ =0x00002E78
	ldr r3, _081FAD24 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FAD28 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	mov r1, sb
	bl FUN_081f22c0
	b _081FAD60
	.align 2, 0
_081FAD1C: .4byte 0x03002CF0
_081FAD20: .4byte 0x00002E78
_081FAD24: .4byte 0x000038E2
_081FAD28: .4byte 0x00000232
_081FAD2C:
	ldr r2, _081FAD70 @ =0x00002E78
	ldr r3, _081FAD74 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FAD78 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	mov r1, sb
	bl FUN_081f22c0
_081FAD60:
	add sp, #0x4c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FAD70: .4byte 0x00002E78
_081FAD74: .4byte 0x000038E2
_081FAD78: .4byte 0x00000232

	thumb_func_start FUN_081fad7c
FUN_081fad7c: @ 0x081FAD7C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	mov ip, r1
	adds r0, #0x4d
	mov r3, sp
	ldrb r4, [r0]
	movs r6, #0x5a
	rsbs r6, r6, #0
	ldr r2, _081FADAC @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r2, #0
	cmp r0, #0
	blt _081FADB0
	asrs r1, r0, #0xc
	b _081FADB6
	.align 2, 0
_081FADAC: .4byte 0x085B0A08
_081FADB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FADB6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081FADCE
	asrs r0, r0, #0xc
	b _081FADD4
_081FADCE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FADD4:
	strh r0, [r3, #4]
	mov r3, sp
	adds r2, r5, #0
	adds r2, #0x50
	mov r1, sp
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r2, _081FAE24 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FAE28 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FAE2C @ =0x0203B400
	adds r0, r0, r1
	ldrb r2, [r0]
	lsls r0, r2, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FAE30
	asrs r1, r0, #0xc
	b _081FAE36
	.align 2, 0
_081FAE24: .4byte 0x030046B8
_081FAE28: .4byte 0x000003FF
_081FAE2C: .4byte 0x0203B400
_081FAE30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAE36:
	mov r0, sp
	ldrh r0, [r0]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FAE5E
	asrs r2, r0, #0xc
	b _081FAE64
_081FAE5E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081FAE64:
	mov r1, sp
	ldrh r0, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	mov r0, sp
	movs r1, #1
	bl FUN_08204d04
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fae7c
FUN_081fae7c: @ 0x081FAE7C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x5c
	adds r5, r0, #0
	add r1, sp, #0x38
	ldr r0, _081FAEF8 @ =0x082526A4
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0]
	str r0, [r1]
	add r0, sp, #0x48
	add r1, sp, #0x4c
	mov r8, r1
	movs r1, #0
	str r1, [sp, #0x48]
	mov r1, r8
	ldr r2, _081FAEFC @ =0x05000002
	bl CpuSet
	ldr r0, _081FAF00 @ =0x03002CF0
	ldr r7, [r0]
	movs r0, #1
	ands r7, r0
	ldr r4, _081FAF04 @ =0x0203B400
	ldr r3, _081FAF08 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081FAF0C @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	ldrb r6, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrb r4, [r0]
	movs r2, #0
	ldrsh r0, [r5, r2]
	movs r3, #2
	ldrsh r2, [r5, r3]
	movs r1, #4
	ldrsh r3, [r5, r1]
	add r1, sp, #0x54
	strh r0, [r1]
	strh r2, [r1, #2]
	strh r3, [r1, #4]
	ldr r2, _081FAF10 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	mov r5, r8
	adds r3, r1, #0
	cmp r0, #0
	blt _081FAF14
	asrs r1, r0, #0xc
	b _081FAF1A
	.align 2, 0
_081FAEF8: .4byte 0x082526A4
_081FAEFC: .4byte 0x05000002
_081FAF00: .4byte 0x03002CF0
_081FAF04: .4byte 0x0203B400
_081FAF08: .4byte 0x030046B8
_081FAF0C: .4byte 0x000003FF
_081FAF10: .4byte 0x085B0A08
_081FAF14:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAF1A:
	ldrh r0, [r3]
	adds r0, r0, r1
	add r1, sp, #0x54
	strh r0, [r1]
	ldr r2, _081FAF40 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081FAF44
	asrs r1, r0, #0xc
	b _081FAF4A
	.align 2, 0
_081FAF40: .4byte 0x085B0A08
_081FAF44:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FAF4A:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r2, _081FAF80 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FAF84 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FAF88 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	adds r0, #0x38
	adds r2, r3, #0
	adds r1, r5, #0
	ldr r0, [r0]
	str r0, [sp]
	cmp r7, #0
	bne _081FAF8C
	movs r0, #0x80
	lsls r0, r0, #2
	b _081FAF90
	.align 2, 0
_081FAF80: .4byte 0x030046B8
_081FAF84: .4byte 0x000003FF
_081FAF88: .4byte 0x0203B400
_081FAF8C:
	movs r0, #0x80
	lsls r0, r0, #3
_081FAF90:
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FAFC8 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	str r0, [sp, #0x24]
	str r0, [sp, #0x28]
	str r0, [sp, #0x2c]
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r2, #0
	ldr r2, _081FAFCC @ =0x00002E78
	ldr r3, _081FAFD0 @ =0x000038E2
	bl FUN_081f22c0
	add sp, #0x5c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FAFC8: .4byte 0x00000232
_081FAFCC: .4byte 0x00002E78
_081FAFD0: .4byte 0x000038E2

	thumb_func_start FUN_081fafd4
FUN_081fafd4: @ 0x081FAFD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FB048 @ =0x05000002
	bl CpuSet
	movs r0, #0
	mov sl, r0
	add r5, sp, #0x44
	ldr r6, _081FB04C @ =0x030046B8
	ldr r1, _081FB050 @ =0x085AE5FC
	mov sb, r1
	ldr r2, _081FB054 @ =0x000003FF
	mov r8, r2
_081FB000:
	mov r0, sb
	ldrh r1, [r0]
	ldr r0, [sp, #0x44]
	ldr r2, _081FB058 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	mov r0, sb
	ldrh r1, [r0, #2]
	ldr r0, [r5, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	mov r1, sl
	cmp r1, #1
	bgt _081FB060
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r1, _081FB05C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	cmp r0, #0
	bge _081FB040
	rsbs r0, r0, #0
_081FB040:
	ldrh r1, [r5]
	adds r1, r1, r0
	b _081FB084
	.align 2, 0
_081FB048: .4byte 0x05000002
_081FB04C: .4byte 0x030046B8
_081FB050: .4byte 0x085AE5FC
_081FB054: .4byte 0x000003FF
_081FB058: .4byte 0xFFFF0000
_081FB05C: .4byte 0x0203B400
_081FB060:
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB0C0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	cmp r0, #0
	bge _081FB080
	rsbs r0, r0, #0
_081FB080:
	ldrh r1, [r5]
	subs r1, r1, r0
_081FB084:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x44]
	ldr r2, _081FB0C4 @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	adds r7, r5, #0
	add r0, sp, #0x44
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FB0BA
	cmp r1, #0
	blt _081FB0BA
	ldr r0, _081FB0C8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB0BA
	ldr r0, _081FB0CC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB0D0
_081FB0BA:
	movs r4, #0
	b _081FB0DE
	.align 2, 0
_081FB0C0: .4byte 0x0203B400
_081FB0C4: .4byte 0xFFFF0000
_081FB0C8: .4byte 0x030046A8
_081FB0CC: .4byte 0x030046AC
_081FB0D0:
	ldr r0, _081FB0F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB0DE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FB0F4
	adds r0, #4
	b _081FB100
	.align 2, 0
_081FB0F0: .4byte 0x030046A4
_081FB0F4:
	ldr r0, _081FB12C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB100:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	strh r0, [r7, #2]
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB130 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FB134
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08204d04
	b _081FB164
	.align 2, 0
_081FB12C: .4byte 0x030046A4
_081FB130: .4byte 0x0203B400
_081FB134:
	movs r0, #3
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FB1A4 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r0, r5, #0
	add r1, sp, #0x3c
	ldr r2, _081FB1A8 @ =0x00002E78
	ldr r3, _081FB1AC @ =0x000038E2
	bl FUN_081f22c0
_081FB164:
	mov r1, sb
	ldrh r0, [r1]
	strh r0, [r5]
	ldrh r0, [r1, #2]
	add r4, sp, #0x44
	strh r0, [r4, #4]
	mov r2, sl
	cmp r2, #0
	beq _081FB17A
	cmp r2, #3
	bne _081FB1B4
_081FB17A:
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB1B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	adds r1, r0, #0
	cmp r1, #0
	bge _081FB19C
	rsbs r1, r1, #0
_081FB19C:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	b _081FB1DA
	.align 2, 0
_081FB1A4: .4byte 0x00000232
_081FB1A8: .4byte 0x00002E78
_081FB1AC: .4byte 0x000038E2
_081FB1B0: .4byte 0x0203B400
_081FB1B4:
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB208 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xc0
	lsls r1, r1, #1
	bl Mod
	adds r1, r0, #0
	cmp r1, #0
	bge _081FB1D6
	rsbs r1, r1, #0
_081FB1D6:
	ldrh r0, [r4, #4]
	subs r0, r0, r1
_081FB1DA:
	strh r0, [r4, #4]
	adds r7, r5, #0
	add r0, sp, #0x44
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FB204
	cmp r1, #0
	blt _081FB204
	ldr r0, _081FB20C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB204
	ldr r0, _081FB210 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB214
_081FB204:
	movs r4, #0
	b _081FB222
	.align 2, 0
_081FB208: .4byte 0x0203B400
_081FB20C: .4byte 0x030046A8
_081FB210: .4byte 0x030046AC
_081FB214:
	ldr r0, _081FB234 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB222:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FB238
	adds r0, #4
	b _081FB244
	.align 2, 0
_081FB234: .4byte 0x030046A4
_081FB238:
	ldr r0, _081FB270 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB244:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	strh r0, [r7, #2]
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FB274 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FB278
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08204d04
	b _081FB2A8
	.align 2, 0
_081FB270: .4byte 0x030046A4
_081FB274: .4byte 0x0203B400
_081FB278:
	movs r0, #3
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FB2C8 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r0, r5, #0
	add r1, sp, #0x3c
	ldr r2, _081FB2CC @ =0x00002E78
	ldr r3, _081FB2D0 @ =0x000038E2
	bl FUN_081f22c0
_081FB2A8:
	movs r0, #4
	add sb, r0
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	bgt _081FB2B8
	b _081FB000
_081FB2B8:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FB2C8: .4byte 0x00000232
_081FB2CC: .4byte 0x00002E78
_081FB2D0: .4byte 0x000038E2

	thumb_func_start FUN_081fb2d4
FUN_081fb2d4: @ 0x081FB2D4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r7, #0
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r6, r7, r0
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FB2FC
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FB2FE
_081FB2FC:
	movs r0, #0
_081FB2FE:
	cmp r0, #0
	beq _081FB310
	adds r0, r6, #0
	bl FUN_081fa590
	movs r1, #4
	adds r0, r4, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FB310:
	ldrb r0, [r6]
	cmp r0, #7
	bls _081FB318
	b _081FB50A
_081FB318:
	lsls r0, r0, #2
	ldr r1, _081FB324 @ =_081FB328
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FB324: .4byte _081FB328
_081FB328: @ jump table
	.4byte _081FB348 @ case 0
	.4byte _081FB3E4 @ case 1
	.4byte _081FB41C @ case 2
	.4byte _081FB450 @ case 3
	.4byte _081FB478 @ case 4
	.4byte _081FB4A0 @ case 5
	.4byte _081FB4AC @ case 6
	.4byte _081FB500 @ case 7
_081FB348:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB398
	add r1, sp, #8
	mov r8, r1
_081FB352:
	mov r0, sp
	movs r1, #0
	bl FUN_08235090
	adds r4, r0, #0
	mov r0, r8
	movs r1, #0
	bl FUN_08235090
	cmp r4, r0
	beq _081FB352
	ldr r3, _081FB394 @ =0x0000083C
	adds r5, r7, r3
	ldr r0, [r5]
	mov r1, sp
	bl FUN_08201054
	movs r0, #0x84
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r0, [r4]
	mov r1, r8
	bl FUN_08201054
	ldr r0, [r5]
	bl FUN_082010b4
	ldr r0, [r4]
	bl FUN_082010b4
	movs r0, #1
	b _081FB39A
	.align 2, 0
_081FB394: .4byte 0x0000083C
_081FB398:
	adds r0, #1
_081FB39A:
	str r0, [r6, #4]
	ldr r1, [r6, #4]
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _081FB3AC
	cmp r1, #2
	beq _081FB3C4
	b _081FB3D4
_081FB3AC:
	ldr r1, _081FB3BC @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB3C0 @ =0x00000694
	adds r0, r0, r3
	bl FUN_081fae7c
	b _081FB3D4
	.align 2, 0
_081FB3BC: .4byte 0x0000083C
_081FB3C0: .4byte 0x00000694
_081FB3C4:
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB3E0 @ =0x00000694
	adds r0, r0, r3
	bl FUN_081fae7c
_081FB3D4:
	ldr r0, [r6, #4]
	cmp r0, #0x1e
	bhi _081FB3DC
	b _081FB50A
_081FB3DC:
	b _081FB4EA
	.align 2, 0
_081FB3E0: .4byte 0x00000694
_081FB3E4:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB410
	ldr r1, _081FB408 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FB40C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
	str r1, [r6, #4]
	b _081FB414
	.align 2, 0
_081FB408: .4byte 0x0000083C
_081FB40C: .4byte 0x000006DB
_081FB410:
	adds r0, #1
	str r0, [r6, #4]
_081FB414:
	ldr r0, [r6, #4]
	cmp r0, #0xa
	bls _081FB50A
	b _081FB4CC
_081FB41C:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB43A
	ldr r3, _081FB448 @ =0x0000083C
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r2, _081FB44C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	adds r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FB43A:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x8c
	bls _081FB50A
	b _081FB4EA
	.align 2, 0
_081FB448: .4byte 0x0000083C
_081FB44C: .4byte 0x000006DB
_081FB450:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB464
	ldr r1, _081FB470 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB474 @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
_081FB464:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x1e
	bls _081FB50A
	b _081FB4EA
	.align 2, 0
_081FB470: .4byte 0x0000083C
_081FB474: .4byte 0x000006DB
_081FB478:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB48E
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB49C @ =0x000006DB
	adds r0, r0, r3
	movs r1, #3
	strb r1, [r0]
_081FB48E:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x1e
	bls _081FB50A
	b _081FB4EA
	.align 2, 0
_081FB49C: .4byte 0x000006DB
_081FB4A0:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	cmp r0, #0x3c
	bls _081FB50A
	b _081FB4EA
_081FB4AC:
	ldr r0, [r6, #4]
	cmp r0, #0
	bne _081FB4CC
	ldr r1, _081FB4F4 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FB4F8 @ =0x000006DB
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FB4CC:
	ldr r1, _081FB4F4 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r3, _081FB4FC @ =0x000006D9
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB50A
	adds r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB50A
_081FB4EA:
	adds r0, r6, #0
	bl FUN_081fa5b0
	b _081FB50A
	.align 2, 0
_081FB4F4: .4byte 0x0000083C
_081FB4F8: .4byte 0x000006DB
_081FB4FC: .4byte 0x000006D9
_081FB500:
	movs r3, #0xfb
	lsls r3, r3, #3
	adds r1, r7, r3
	movs r0, #1
	strh r0, [r1]
_081FB50A:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fb518
FUN_081fb518: @ 0x081FB518
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r1, r6, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FB53A
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FB53C
_081FB53A:
	movs r0, #0
_081FB53C:
	cmp r0, #0
	beq _081FB546
	adds r0, r4, #0
	bl FUN_081fa590
_081FB546:
	ldrb r0, [r4]
	cmp r0, #0
	beq _081FB566
	cmp r0, #4
	beq _081FB566
	cmp r0, #5
	beq _081FB566
	adds r0, r5, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #5
	bne _081FB566
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081fa5a0
_081FB566:
	ldrb r0, [r4]
	cmp r0, #5
	bhi _081FB65C
	lsls r0, r0, #2
	ldr r1, _081FB578 @ =_081FB57C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FB578: .4byte _081FB57C
_081FB57C: @ jump table
	.4byte _081FB594 @ case 0
	.4byte _081FB5E8 @ case 1
	.4byte _081FB624 @ case 2
	.4byte _081FB610 @ case 3
	.4byte _081FB634 @ case 4
	.4byte _081FB652 @ case 5
_081FB594:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FB5D4
	ldr r2, _081FB5C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FB5CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FB5D0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #3
	ands r2, r0
	adds r0, r6, #0
	movs r1, #6
	bl FUN_081fc890
	movs r1, #1
	adds r0, r5, #0
	adds r0, #0xa2
	strb r1, [r0]
	str r1, [r4, #4]
	b _081FB65C
	.align 2, 0
_081FB5C8: .4byte 0x030046B8
_081FB5CC: .4byte 0x000003FF
_081FB5D0: .4byte 0x0203B400
_081FB5D4:
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB65C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081fa5a0
	b _081FB65C
_081FB5E8:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FB5FC
	movs r0, #6
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
	movs r0, #1
	str r0, [r4, #4]
	b _081FB65C
_081FB5FC:
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB65C
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081fa5a0
	b _081FB65C
_081FB610:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #1
	bls _081FB65C
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081fa5a0
	b _081FB65C
_081FB624:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FB648
	movs r1, #3
	adds r0, r5, #0
	adds r0, #0xa2
	strb r1, [r0]
	b _081FB648
_081FB634:
	adds r0, r5, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FB648
	adds r0, r5, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #3
	bne _081FB65C
_081FB648:
	adds r0, r4, #0
	movs r1, #5
	bl FUN_081fa5a0
	b _081FB65C
_081FB652:
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #1
	strh r0, [r1]
_081FB65C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fb664
FUN_081fb664: @ 0x081FB664
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xb4
	mov sb, r0
	mov r4, sb
	movs r5, #0xfe
	lsls r5, r5, #1
	add r5, sb
	mov r1, sb
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FB690
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FB692
_081FB690:
	movs r0, #0
_081FB692:
	cmp r0, #0
	beq _081FB69C
	adds r0, r5, #0
	bl FUN_081fa590
_081FB69C:
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #5
	bne _081FB6B8
	adds r0, r4, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FB6B8
	movs r0, #3
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
_081FB6B8:
	ldrb r0, [r5]
	cmp r0, #6
	bls _081FB6C0
	b _081FBAF8
_081FB6C0:
	lsls r0, r0, #2
	ldr r1, _081FB6CC @ =_081FB6D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FB6CC: .4byte _081FB6D0
_081FB6D0: @ jump table
	.4byte _081FB6EC @ case 0
	.4byte _081FB756 @ case 1
	.4byte _081FB908 @ case 2
	.4byte _081FB91E @ case 3
	.4byte _081FBAD0 @ case 4
	.4byte _081FBAE4 @ case 5
	.4byte _081FBAEE @ case 6
_081FB6EC:
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _081FB74C
	ldr r2, _081FB718 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FB71C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FB720 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FB724
	mov r0, sb
	movs r1, #2
	movs r2, #0
	bl FUN_081fc890
	b _081FB72E
	.align 2, 0
_081FB718: .4byte 0x030046B8
_081FB71C: .4byte 0x000003FF
_081FB720: .4byte 0x0203B400
_081FB724:
	mov r0, sb
	movs r1, #5
	movs r2, #0
	bl FUN_081fc890
_081FB72E:
	movs r1, #1
	adds r0, r4, #0
	adds r0, #0xa2
	strb r1, [r0]
	movs r1, #0
	movs r2, #0
	movs r0, #0x81
	lsls r0, r0, #4
	add r0, sb
_081FB740:
	strb r2, [r0]
	strb r1, [r0, #8]
	adds r0, #1
	adds r1, #1
	cmp r1, #7
	ble _081FB740
_081FB74C:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081fa5a0
	b _081FBAF8
_081FB756:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	beq _081FB768
	b _081FB8E2
_081FB768:
	add r4, sp, #0x94
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08235090
	adds r6, r4, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _081FB79A
	cmp r1, #0
	blt _081FB79A
	ldr r0, _081FB7A0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB79A
	ldr r0, _081FB7A4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB7A8
_081FB79A:
	movs r4, #0
	b _081FB7B6
	.align 2, 0
_081FB7A0: .4byte 0x030046A8
_081FB7A4: .4byte 0x030046AC
_081FB7A8:
	ldr r0, _081FB7C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB7B6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FB7CC
	adds r0, #4
	b _081FB7D8
	.align 2, 0
_081FB7C8: .4byte 0x030046A4
_081FB7CC:
	ldr r0, _081FB8F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB7D8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	ldr r0, _081FB8F8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	mov r8, r0
	add r0, sp, #0x94
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r0, _081FB8FC @ =0x00000237
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_081e9f78
	ldrh r0, [r7, #2]
	adds r0, #0x20
	strh r0, [r7, #2]
	add r0, sp, #0xc
	mov r2, r8
	ldrh r1, [r2, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _081FB900 @ =0xFFFF0000
	add r7, sp, #0x9c
	ldr r0, [r7]
	ands r0, r6
	orrs r0, r1
	str r0, [r7]
	add r0, sp, #0xc
	ldrh r1, [r2, #0xc]
	ldrh r0, [r0, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r7, #0
	ldr r0, [r4, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4, #4]
	ldrh r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0x30
	ble _081FB882
	adds r0, r6, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4]
_081FB882:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081FB898
	ldr r0, [r4]
	ands r0, r6
	ldr r1, _081FB904 @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4]
_081FB898:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0x30
	ble _081FB8AA
	ldr r0, [r4, #4]
	ands r0, r6
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4, #4]
_081FB8AA:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bge _081FB8BC
	ldr r0, [r4, #4]
	ands r0, r6
	ldr r1, _081FB904 @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4, #4]
_081FB8BC:
	movs r0, #0xfe
	lsls r0, r0, #3
	add r0, sb
	movs r2, #0
	ldrsh r3, [r0, r2]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xa
	str r0, [sp, #8]
	add r0, sp, #0xc
	mov r1, r8
	adds r2, r7, #0
	bl FUN_081ea524
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_081FB8E2:
	ldr r0, [r5, #8]
	cmp r0, #3
	bhi _081FB8EA
	b _081FBAF8
_081FB8EA:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081fa5a0
	b _081FBAF8
	.align 2, 0
_081FB8F4: .4byte 0x030046A4
_081FB8F8: .4byte 0x03002BE0
_081FB8FC: .4byte 0x00000237
_081FB900: .4byte 0xFFFF0000
_081FB904: .4byte 0x0000FFD0
_081FB908:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0x5a
	bhi _081FB914
	b _081FBAF8
_081FB914:
	adds r0, r5, #0
	movs r1, #3
	bl FUN_081fa5a0
	b _081FBAF8
_081FB91E:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	beq _081FB930
	b _081FBAAC
_081FB930:
	add r4, sp, #0xa4
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08235090
	adds r6, r4, #0
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _081FB962
	cmp r1, #0
	blt _081FB962
	ldr r0, _081FB968 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FB962
	ldr r0, _081FB96C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FB970
_081FB962:
	movs r4, #0
	b _081FB97E
	.align 2, 0
_081FB968: .4byte 0x030046A8
_081FB96C: .4byte 0x030046AC
_081FB970:
	ldr r0, _081FB990 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FB97E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FB994
	adds r0, #4
	b _081FB9A0
	.align 2, 0
_081FB990: .4byte 0x030046A4
_081FB994:
	ldr r0, _081FBABC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FB9A0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	ldr r0, _081FBAC0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	mov sl, r0
	add r0, sp, #0xa4
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x58]
	str r1, [sp, #0x5c]
	ldr r0, _081FBAC4 @ =0x00000237
	str r0, [sp]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_081e9f78
	ldrh r0, [r7, #2]
	adds r0, #0x20
	strh r0, [r7, #2]
	add r0, sp, #0x50
	mov r8, r0
	mov r2, sl
	ldrh r1, [r2, #8]
	ldrh r0, [r0, #8]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _081FBAC8 @ =0xFFFF0000
	add r7, sp, #0xac
	ldr r0, [r7]
	ands r0, r6
	orrs r0, r1
	str r0, [r7]
	ldrh r1, [r2, #0xc]
	mov r2, r8
	ldrh r0, [r2, #0xc]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r4, r7, #0
	ldr r0, [r4, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r1, #0x3c
	bl Div
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r6
	orrs r1, r0
	str r1, [r4, #4]
	ldrh r1, [r4]
	movs r0, #0xf0
	lsls r0, r0, #0xd
	orrs r1, r0
	str r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0x30
	ble _081FBA4C
	adds r0, r6, #0
	ands r0, r1
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4]
_081FBA4C:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0x30
	rsbs r2, r2, #0
	cmp r0, r2
	bge _081FBA62
	ldr r0, [r4]
	ands r0, r6
	ldr r1, _081FBACC @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4]
_081FBA62:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, #0x30
	ble _081FBA74
	ldr r0, [r4, #4]
	ands r0, r6
	movs r1, #0x30
	orrs r0, r1
	str r0, [r4, #4]
_081FBA74:
	movs r1, #4
	ldrsh r0, [r4, r1]
	cmp r0, r2
	bge _081FBA86
	ldr r0, [r4, #4]
	ands r0, r6
	ldr r1, _081FBACC @ =0x0000FFD0
	orrs r0, r1
	str r0, [r4, #4]
_081FBA86:
	movs r0, #0xfe
	lsls r0, r0, #3
	add r0, sb
	movs r2, #0
	ldrsh r3, [r0, r2]
	movs r0, #0x1e
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xa
	str r0, [sp, #8]
	mov r0, r8
	mov r1, sl
	adds r2, r7, #0
	bl FUN_081ea524
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_081FBAAC:
	ldr r0, [r5, #8]
	cmp r0, #3
	bls _081FBAF8
	adds r0, r5, #0
	movs r1, #4
	bl FUN_081fa5a0
	b _081FBAF8
	.align 2, 0
_081FBABC: .4byte 0x030046A4
_081FBAC0: .4byte 0x03002BE0
_081FBAC4: .4byte 0x00000237
_081FBAC8: .4byte 0xFFFF0000
_081FBACC: .4byte 0x0000FFD0
_081FBAD0:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0x14
	bls _081FBAF8
	adds r0, r5, #0
	movs r1, #5
	bl FUN_081fa5a0
	b _081FBAF8
_081FBAE4:
	adds r0, r5, #0
	movs r1, #6
	bl FUN_081fa5a0
	b _081FBAF8
_081FBAEE:
	movs r1, #0xfb
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strh r0, [r1]
_081FBAF8:
	add sp, #0xb4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fbb08
FUN_081fbb08: @ 0x081FBB08
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	str r7, [sp, #0x10]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sb, r0
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FBB36
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FBB38
_081FBB36:
	movs r0, #0
_081FBB38:
	cmp r0, #0
	beq _081FBC0E
	mov r0, sb
	bl FUN_081fa590
	ldr r3, _081FBC24 @ =0x0203B400
	ldr r2, _081FBC28 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FBC2C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r4, [r0]
	movs r0, #1
	ands r4, r0
	movs r6, #0
	mov r8, r3
	movs r1, #0x81
	lsls r1, r1, #4
	adds r5, r7, r1
	movs r3, #0
_081FBB66:
	strb r3, [r5]
	strb r4, [r5, #8]
	adds r4, #1
	adds r0, r6, #5
	cmp r4, r0
	bge _081FBB8C
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FBC2C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _081FBB8C
	adds r4, #1
_081FBB8C:
	adds r5, #1
	adds r6, #1
	cmp r6, #7
	ble _081FBB66
	movs r6, #0
	ldr r2, _081FBC28 @ =0x030046B8
	mov r8, r2
	ldr r3, _081FBC2C @ =0x000003FF
	mov sl, r3
_081FBB9E:
	adds r6, #1
_081FBBA0:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _081FBC24 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #8
	bl Mod
	adds r5, r0, #0
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _081FBC24 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #8
	bl Mod
	adds r4, r0, #0
	cmp r5, r4
	beq _081FBBA0
	ldr r0, _081FBC30 @ =0x00000818
	adds r1, r7, r0
	adds r2, r1, r5
	movs r3, #0
	ldrsb r3, [r2, r3]
	adds r1, r1, r4
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r2, r1, r5
	movs r3, #0
	ldrsb r3, [r2, r3]
	adds r1, r1, r4
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	cmp r6, #7
	ble _081FBB9E
	ldr r3, _081FBC34 @ =0x00000838
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
_081FBC0E:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #6
	bls _081FBC18
	b _081FC08E
_081FBC18:
	lsls r0, r0, #2
	ldr r1, _081FBC38 @ =_081FBC3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FBC24: .4byte 0x0203B400
_081FBC28: .4byte 0x030046B8
_081FBC2C: .4byte 0x000003FF
_081FBC30: .4byte 0x00000818
_081FBC34: .4byte 0x00000838
_081FBC38: .4byte _081FBC3C
_081FBC3C: @ jump table
	.4byte _081FBC58 @ case 0
	.4byte _081FBD2A @ case 1
	.4byte _081FBD88 @ case 2
	.4byte _081FBDC0 @ case 3
	.4byte _081FC020 @ case 4
	.4byte _081FC02E @ case 5
	.4byte _081FC084 @ case 6
_081FBC58:
	mov r2, sb
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FBD18
	movs r5, #0
	mov r6, sp
_081FBC64:
	movs r3, #0x81
	lsls r3, r3, #4
	adds r0, r7, r3
	adds r0, r0, r5
	ldrb r1, [r0]
	ldr r2, _081FBCA4 @ =0x00000818
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r2, [r0]
	mov r0, sp
	bl FUN_08234f90
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FBCA0
	cmp r1, #0
	blt _081FBCA0
	ldr r0, _081FBCA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FBCA0
	ldr r0, _081FBCAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FBCB0
_081FBCA0:
	movs r4, #0
	b _081FBCBE
	.align 2, 0
_081FBCA4: .4byte 0x00000818
_081FBCA8: .4byte 0x030046A8
_081FBCAC: .4byte 0x030046AC
_081FBCB0:
	ldr r0, _081FBCD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FBCBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FBCD4
	adds r0, #4
	b _081FBCE0
	.align 2, 0
_081FBCD0: .4byte 0x030046A4
_081FBCD4:
	ldr r0, _081FBD10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FBCE0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r5, #2
	ldr r3, _081FBD14 @ =0x0000083C
	adds r4, r7, r3
	adds r4, r4, r0
	ldr r0, [r4]
	mov r1, sp
	bl FUN_08201054
	ldr r0, [r4]
	bl FUN_082010b4
	adds r5, #1
	cmp r5, #1
	ble _081FBC64
	movs r0, #1
	mov r1, sb
	str r0, [r1, #4]
	b _081FBD1E
	.align 2, 0
_081FBD10: .4byte 0x030046A4
_081FBD14: .4byte 0x0000083C
_081FBD18:
	adds r0, #1
	mov r2, sb
	str r0, [r2, #4]
_081FBD1E:
	mov r3, sb
	ldr r0, [r3, #4]
	cmp r0, #0x96
	bhi _081FBD28
	b _081FC08E
_081FBD28:
	b _081FC070
_081FBD2A:
	mov r1, sb
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FBD5C
	ldr r2, _081FBD54 @ =0x0000083C
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r2, _081FBD58 @ =0x000006DB
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
	mov r0, sb
	str r1, [r0, #4]
	b _081FBD62
	.align 2, 0
_081FBD54: .4byte 0x0000083C
_081FBD58: .4byte 0x000006DB
_081FBD5C:
	adds r0, #1
	mov r1, sb
	str r0, [r1, #4]
_081FBD62:
	ldr r2, _081FBD80 @ =0x0000083C
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r3, _081FBD84 @ =0x000006D9
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FBD74
	b _081FC08E
_081FBD74:
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r3
	b _081FC06A
	.align 2, 0
_081FBD80: .4byte 0x0000083C
_081FBD84: .4byte 0x000006D9
_081FBD88:
	mov r2, sb
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FBDA8
	ldr r3, _081FBDB8 @ =0x0000083C
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r2, _081FBDBC @ =0x000006DB
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	adds r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FBDA8:
	mov r1, sb
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x14
	bhi _081FBDB6
	b _081FC08E
_081FBDB6:
	b _081FC070
	.align 2, 0
_081FBDB8: .4byte 0x0000083C
_081FBDBC: .4byte 0x000006DB
_081FBDC0:
	mov r2, sb
	ldrb r1, [r2, #1]
	cmp r1, #1
	beq _081FBE10
	cmp r1, #1
	bgt _081FBDD2
	cmp r1, #0
	beq _081FBDE0
	b _081FC08E
_081FBDD2:
	cmp r1, #2
	bne _081FBDD8
	b _081FBFE0
_081FBDD8:
	cmp r1, #3
	bne _081FBDDE
	b _081FC070
_081FBDDE:
	b _081FC08E
_081FBDE0:
	mov r3, sb
	ldr r0, [r3, #8]
	cmp r0, #0
	beq _081FBDEA
	b _081FC08E
_081FBDEA:
	ldr r1, _081FBE08 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FBE0C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
	b _081FC00E
	.align 2, 0
_081FBE08: .4byte 0x0000083C
_081FBE0C: .4byte 0x000006DB
_081FBE10:
	mov r2, sb
	ldr r0, [r2, #8]
	cmp r0, #0
	bne _081FBE26
	str r1, [r2, #8]
	ldr r3, _081FBE64 @ =0x00000838
	adds r0, r7, r3
	movs r1, #2
	strb r1, [r0]
	movs r0, #0x1f
	str r0, [r2, #4]
_081FBE26:
	movs r0, #0
	str r0, [sp, #0x18]
	movs r1, #0
	str r1, [sp, #0x1c]
	mov r2, sp
	adds r2, #8
	str r2, [sp, #0x20]
	mov r8, r1
	movs r3, #1
	str r3, [sp, #0x14]
_081FBE3A:
	ldr r1, _081FBE68 @ =0x0000083C
	adds r0, r7, r1
	add r0, r8
	ldr r5, [r0]
	ldr r2, _081FBE6C @ =0x000006D9
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FBE4E
	b _081FBF9C
_081FBE4E:
	ldr r3, _081FBE70 @ =0x000006DC
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081FBE7E
	cmp r0, #2
	bgt _081FBE74
	cmp r0, #1
	bne _081FBE62
	b _081FBF94
_081FBE62:
	b _081FBF9C
	.align 2, 0
_081FBE64: .4byte 0x00000838
_081FBE68: .4byte 0x0000083C
_081FBE6C: .4byte 0x000006D9
_081FBE70: .4byte 0x000006DC
_081FBE74:
	cmp r0, #3
	beq _081FBEA8
	cmp r0, #5
	beq _081FBECC
	b _081FBF9C
_081FBE7E:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bne _081FBE9E
	mov r1, sb
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x1e
	bls _081FBE9E
	ldr r2, _081FBEA4 @ =0x000006DB
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
	ldr r3, [sp, #0x1c]
	mov r0, sb
	str r3, [r0, #4]
_081FBE9E:
	movs r1, #1
	str r1, [sp, #0x1c]
	b _081FBF9C
	.align 2, 0
_081FBEA4: .4byte 0x000006DB
_081FBEA8:
	ldr r2, _081FBEBC @ =0x00000838
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #7
	bhi _081FBEC4
	ldr r3, _081FBEC0 @ =0x000006DB
	adds r1, r5, r3
	movs r0, #5
	b _081FBF9A
	.align 2, 0
_081FBEBC: .4byte 0x00000838
_081FBEC0: .4byte 0x000006DB
_081FBEC4:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
	b _081FBF9C
_081FBECC:
	ldr r2, _081FBF1C @ =0x00000838
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #7
	bhi _081FBF9C
	adds r2, r0, #0
	movs r3, #0x81
	lsls r3, r3, #4
	adds r0, r7, r3
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r3, #8
	adds r0, r7, r3
	adds r0, r0, r2
	ldrb r2, [r0]
	ldr r0, [sp, #0x20]
	bl FUN_08234f90
	ldr r6, [sp, #0x20]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sl, r6
	cmp r2, #0
	blt _081FBF18
	cmp r1, #0
	blt _081FBF18
	ldr r0, _081FBF20 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FBF18
	ldr r0, _081FBF24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FBF28
_081FBF18:
	movs r4, #0
	b _081FBF36
	.align 2, 0
_081FBF1C: .4byte 0x00000838
_081FBF20: .4byte 0x030046A8
_081FBF24: .4byte 0x030046AC
_081FBF28:
	ldr r0, _081FBF48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FBF36:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FBF4C
	adds r0, #4
	b _081FBF58
	.align 2, 0
_081FBF48: .4byte 0x030046A4
_081FBF4C:
	ldr r0, _081FBF84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FBF58:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	adds r0, r5, #0
	mov r1, sl
	bl FUN_08201054
	ldr r1, _081FBF88 @ =0x0000083C
	adds r0, r7, r1
	add r0, r8
	ldr r0, [r0]
	ldr r2, _081FBF8C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081FBF90 @ =0x00000838
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #1
	b _081FBF9A
	.align 2, 0
_081FBF84: .4byte 0x030046A4
_081FBF88: .4byte 0x0000083C
_081FBF8C: .4byte 0x000006DB
_081FBF90: .4byte 0x00000838
_081FBF94:
	ldr r0, _081FBFD8 @ =0x000006DB
	adds r1, r5, r0
	movs r0, #2
_081FBF9A:
	strb r0, [r1]
_081FBF9C:
	movs r1, #4
	add r8, r1
	ldr r2, [sp, #0x14]
	subs r2, #1
	str r2, [sp, #0x14]
	cmp r2, #0
	blt _081FBFAC
	b _081FBE3A
_081FBFAC:
	ldr r3, _081FBFDC @ =0x00000838
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #7
	bls _081FBFBC
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bgt _081FBFCC
_081FBFBC:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [sp, #0x10]
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081FC08E
_081FBFCC:
	mov r0, sb
	movs r1, #2
	bl FUN_081fa5d0
	b _081FC08E
	.align 2, 0
_081FBFD8: .4byte 0x000006DB
_081FBFDC: .4byte 0x00000838
_081FBFE0:
	mov r1, sb
	ldr r0, [r1, #8]
	cmp r0, #0
	bne _081FC002
	ldr r2, _081FC018 @ =0x0000083C
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r2, _081FC01C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FC002:
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	cmp r0, #0x1e
	bls _081FC08E
_081FC00E:
	mov r0, sb
	bl FUN_081fa5dc
	b _081FC08E
	.align 2, 0
_081FC018: .4byte 0x0000083C
_081FC01C: .4byte 0x000006DB
_081FC020:
	mov r2, sb
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	cmp r0, #0x3c
	bls _081FC08E
	b _081FC070
_081FC02E:
	mov r3, sb
	ldr r0, [r3, #4]
	cmp r0, #0
	bne _081FC050
	ldr r1, _081FC078 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FC07C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FC050:
	ldr r1, _081FC078 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FC080 @ =0x000006D9
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FC08E
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
_081FC06A:
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FC08E
_081FC070:
	mov r0, sb
	bl FUN_081fa5b0
	b _081FC08E
	.align 2, 0
_081FC078: .4byte 0x0000083C
_081FC07C: .4byte 0x000006DB
_081FC080: .4byte 0x000006D9
_081FC084:
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
_081FC08E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fc0a0
FUN_081fc0a0: @ 0x081FC0A0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC0C2
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC0C4
_081FC0C2:
	movs r0, #0
_081FC0C4:
	cmp r0, #0
	beq _081FC0CE
	adds r0, r4, #0
	bl FUN_081fa590
_081FC0CE:
	ldrb r0, [r4]
	cmp r0, #1
	beq _081FC152
	cmp r0, #1
	bgt _081FC0DE
	cmp r0, #0
	beq _081FC0E8
	b _081FC1DC
_081FC0DE:
	cmp r0, #2
	beq _081FC1A6
	cmp r0, #3
	beq _081FC1C8
	b _081FC1DC
_081FC0E8:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FC13A
	ldr r2, _081FC118 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FC11C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FC120 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081FC124
	adds r0, r5, #0
	movs r1, #2
	movs r2, #1
	bl FUN_081fc890
	b _081FC12E
	.align 2, 0
_081FC118: .4byte 0x030046B8
_081FC11C: .4byte 0x000003FF
_081FC120: .4byte 0x0203B400
_081FC124:
	adds r0, r5, #0
	movs r1, #5
	movs r2, #1
	bl FUN_081fc890
_081FC12E:
	movs r1, #1
	adds r0, r6, #0
	adds r0, #0xa2
	strb r1, [r0]
	str r1, [r4, #4]
	b _081FC1DC
_081FC13A:
	adds r0, #1
	str r0, [r4, #4]
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #1
	bne _081FC1DC
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081fa5a0
	b _081FC1DC
_081FC152:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FC18E
	ldr r2, _081FC174 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FC178 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FC17C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FC180
	movs r1, #7
	b _081FC182
	.align 2, 0
_081FC174: .4byte 0x030046B8
_081FC178: .4byte 0x000003FF
_081FC17C: .4byte 0x0203B400
_081FC180:
	movs r1, #8
_081FC182:
	adds r0, r6, #0
	adds r0, #0xa2
	strb r1, [r0]
	movs r0, #1
	str r0, [r4, #4]
	b _081FC1DC
_081FC18E:
	adds r0, #1
	str r0, [r4, #4]
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #1
	bne _081FC1DC
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081fa5a0
	b _081FC1DC
_081FC1A6:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FC1B4
	movs r1, #3
	adds r0, r6, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FC1B4:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x1e
	bls _081FC1DC
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081fa5a0
	b _081FC1DC
_081FC1C8:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x3c
	bls _081FC1DC
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
_081FC1DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fc1e4
FUN_081fc1e4: @ 0x081FC1E4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r4, r5, r0
	adds r1, r5, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC206
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC208
_081FC206:
	movs r0, #0
_081FC208:
	cmp r0, #0
	beq _081FC212
	adds r0, r4, #0
	bl FUN_081fa590
_081FC212:
	ldrb r0, [r4]
	cmp r0, #1
	beq _081FC236
	cmp r0, #1
	bgt _081FC222
	cmp r0, #0
	beq _081FC22C
	b _081FC28E
_081FC222:
	cmp r0, #2
	beq _081FC262
	cmp r0, #3
	beq _081FC284
	b _081FC28E
_081FC22C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081fa5a0
	b _081FC28E
_081FC236:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FC244
	movs r0, #9
	adds r1, r6, #0
	adds r1, #0xa2
	strb r0, [r1]
_081FC244:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0xa
	bls _081FC28E
	adds r0, r6, #0
	adds r0, #0xa7
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FC28E
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081fa5a0
	b _081FC28E
_081FC262:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FC270
	movs r1, #3
	adds r0, r6, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FC270:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x14
	bls _081FC28E
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081fa5a0
	b _081FC28E
_081FC284:
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
_081FC28E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc294
FUN_081fc294: @ 0x081FC294
	bx lr
	.align 2, 0

	thumb_func_start FUN_081fc298
FUN_081fc298: @ 0x081FC298
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r5, r4, #0
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r6, r4, r0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC2C0
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC2C2
_081FC2C0:
	movs r0, #0
_081FC2C2:
	cmp r0, #0
	beq _081FC322
	adds r0, r6, #0
	bl FUN_081fa590
	movs r1, #0x10
	adds r0, r5, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081FC2F0
	adds r0, r5, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #3
	beq _081FC2F0
	cmp r0, #4
	beq _081FC2F0
	movs r0, #3
	adds r1, r5, #0
	adds r1, #0xa2
	strb r0, [r1]
_081FC2F0:
	ldr r1, _081FC330 @ =0x0000083C
	adds r2, r4, r1
	ldr r7, _081FC334 @ =0x000006DC
	mov r8, r7
	ldr r0, _081FC338 @ =0x000006DB
	mov ip, r0
	movs r1, #5
	mov sb, r1
	movs r3, #1
_081FC302:
	ldr r1, [r2]
	mov r7, r8
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #5
	beq _081FC31A
	cmp r0, #7
	beq _081FC31A
	mov r7, ip
	adds r0, r1, r7
	mov r1, sb
	strb r1, [r0]
_081FC31A:
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _081FC302
_081FC322:
	ldrb r1, [r6]
	cmp r1, #0
	beq _081FC33C
	cmp r1, #1
	beq _081FC380
	b _081FC388
	.align 2, 0
_081FC330: .4byte 0x0000083C
_081FC334: .4byte 0x000006DC
_081FC338: .4byte 0x000006DB
_081FC33C:
	movs r1, #0x10
	adds r0, r5, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081FC388
	ldr r2, _081FC378 @ =0x0000083C
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r7, _081FC37C @ =0x000006DC
	adds r0, r0, r7
	ldrb r0, [r0]
	cmp r0, #7
	bne _081FC388
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r0, [r0]
	adds r2, r7, #0
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #7
	bne _081FC388
	adds r0, r6, #0
	movs r1, #1
	bl FUN_081fa5a0
	b _081FC388
	.align 2, 0
_081FC378: .4byte 0x0000083C
_081FC37C: .4byte 0x000006DC
_081FC380:
	movs r7, #0xfb
	lsls r7, r7, #3
	adds r0, r4, r7
	strh r1, [r0]
_081FC388:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc394
FUN_081fc394: @ 0x081FC394
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r4, r5, r0
	movs r1, #0
	mov sl, r1
	movs r2, #0
	mov sb, r2
	mov r0, sb
	strh r0, [r4]
	ldr r1, _081FC3E4 @ =0x085AE60C
	adds r6, r5, #0
	adds r6, #0xa6
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _081FC3CE
	b _081FC5A8
_081FC3CE:
	ldr r1, _081FC3E8 @ =0x000007DA
	adds r1, r1, r5
	mov r8, r1
	ldrh r7, [r1]
	cmp r7, #1
	beq _081FC474
	cmp r7, #1
	bgt _081FC3EC
	cmp r7, #0
	beq _081FC3F4
	b _081FC5A8
	.align 2, 0
_081FC3E4: .4byte 0x085AE60C
_081FC3E8: .4byte 0x000007DA
_081FC3EC:
	cmp r7, #2
	bne _081FC3F2
	b _081FC51C
_081FC3F2:
	b _081FC5A8
_081FC3F4:
	adds r0, r5, #0
	adds r0, #0x90
	movs r2, #0
	ldrsh r4, [r0, r2]
	adds r0, #2
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0xa
	bl Div
	lsls r1, r0, #3
	subs r1, r1, r0
	cmp r4, r1
	bge _081FC43A
	ldrb r0, [r6]
	cmp r0, #7
	beq _081FC422
	movs r0, #7
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC422:
	movs r1, #1
	movs r0, #1
	mov r2, r8
	strh r0, [r2]
	mov r0, sl
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _081FC5A8
_081FC43A:
	ldrb r0, [r6]
	cmp r0, #2
	beq _081FC45C
	cmp r0, #2
	bgt _081FC44A
	cmp r0, #0
	beq _081FC450
	b _081FC5A8
_081FC44A:
	cmp r0, #5
	beq _081FC468
	b _081FC5A8
_081FC450:
	movs r0, #2
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC45C:
	movs r0, #5
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC468:
	mov r1, sl
	strb r1, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	str r7, [r0]
	b _081FC5A0
_081FC474:
	adds r0, r5, #0
	adds r0, #0x90
	adds r1, r5, #0
	adds r1, #0x92
	ldrh r1, [r1]
	lsls r1, r1, #0x10
	movs r2, #0
	ldrsh r0, [r0, r2]
	asrs r1, r1, #0x12
	cmp r0, r1
	bge _081FC4AC
	ldrb r0, [r6]
	cmp r0, #7
	beq _081FC494
	movs r0, #7
	b _081FC49C
_081FC494:
	movs r0, #2
	mov r2, r8
	strh r0, [r2]
	movs r0, #3
_081FC49C:
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xbc
	mov r1, sb
	str r1, [r0]
	subs r0, #0x14
	strb r7, [r0]
	b _081FC5A8
_081FC4AC:
	ldrb r0, [r6]
	cmp r0, #5
	bls _081FC4B4
	b _081FC5A8
_081FC4B4:
	lsls r0, r0, #2
	ldr r1, _081FC4C0 @ =_081FC4C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FC4C0: .4byte _081FC4C4
_081FC4C4: @ jump table
	.4byte _081FC4DC @ case 0
	.4byte _081FC504 @ case 1
	.4byte _081FC50C @ case 2
	.4byte _081FC5A8 @ case 3
	.4byte _081FC508 @ case 4
	.4byte _081FC510 @ case 5
_081FC4DC:
	ldr r2, _081FC4F8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FC4FC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FC500 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x7f
	ble _081FC560
	movs r0, #4
	b _081FC592
	.align 2, 0
_081FC4F8: .4byte 0x030046B8
_081FC4FC: .4byte 0x000003FF
_081FC500: .4byte 0x0203B400
_081FC504:
	movs r0, #2
	b _081FC592
_081FC508:
	movs r0, #2
	b _081FC592
_081FC50C:
	movs r0, #5
	b _081FC592
_081FC510:
	movs r1, #0
	adds r0, r5, #0
	adds r0, #0xa6
	strb r1, [r0]
	adds r0, #0x16
	b _081FC59E
_081FC51C:
	ldrb r0, [r6]
	subs r0, #1
	cmp r0, #4
	bhi _081FC5A8
	lsls r0, r0, #2
	ldr r1, _081FC530 @ =_081FC534
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FC530: .4byte _081FC534
_081FC534: @ jump table
	.4byte _081FC584 @ case 0
	.4byte _081FC58C @ case 1
	.4byte _081FC548 @ case 2
	.4byte _081FC588 @ case 3
	.4byte _081FC590 @ case 4
_081FC548:
	ldr r2, _081FC574 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FC578 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FC57C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FC580
_081FC560:
	movs r2, #1
	adds r0, r5, #0
	adds r0, #0xa6
	movs r1, #0
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _081FC5A8
	.align 2, 0
_081FC574: .4byte 0x030046B8
_081FC578: .4byte 0x000003FF
_081FC57C: .4byte 0x0203B400
_081FC580:
	movs r0, #4
	b _081FC592
_081FC584:
	movs r0, #2
	b _081FC592
_081FC588:
	movs r0, #2
	b _081FC592
_081FC58C:
	movs r0, #5
	b _081FC592
_081FC590:
	movs r0, #3
_081FC592:
	adds r2, r5, #0
	adds r2, #0xa6
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
_081FC59E:
	str r1, [r0]
_081FC5A0:
	adds r1, r5, #0
	adds r1, #0xa8
	movs r0, #1
	strb r0, [r1]
_081FC5A8:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fc5b8
FUN_081fc5b8: @ 0x081FC5B8
	push {lr}
	ldr r2, _081FC5D0 @ =0x085AE62C
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_081FC5D0: .4byte 0x085AE62C

	thumb_func_start FUN_081fc5d4
FUN_081fc5d4: @ 0x081FC5D4
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC5EE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC5F0
_081FC5EE:
	movs r0, #0
_081FC5F0:
	cmp r0, #0
	beq _081FC5FC
	movs r1, #0xb
	adds r0, r2, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FC5FC:
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc600
FUN_081fc600: @ 0x081FC600
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC61A
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC61C
_081FC61A:
	movs r0, #0
_081FC61C:
	cmp r0, #0
	beq _081FC628
	movs r1, #0xc
	adds r0, r2, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FC628:
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc62c
FUN_081fc62c: @ 0x081FC62C
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC646
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC648
_081FC646:
	movs r0, #0
_081FC648:
	cmp r0, #0
	beq _081FC654
	movs r1, #0xd
	adds r0, r2, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FC654:
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc658
FUN_081fc658: @ 0x081FC658
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC672
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC678
_081FC672:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_081FC678:
	cmp r0, #0
	beq _081FC684
	movs r0, #0xe
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_081FC684:
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC696
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
_081FC696:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fc69c
FUN_081fc69c: @ 0x081FC69C
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC6B6
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC6BC
_081FC6B6:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_081FC6BC:
	cmp r0, #0
	beq _081FC6C8
	movs r0, #0xf
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_081FC6C8:
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC6DA
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
_081FC6DA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fc6e0
FUN_081fc6e0: @ 0x081FC6E0
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC6FA
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC700
_081FC6FA:
	movs r0, #0
	adds r1, r3, #0
	adds r1, #0xa7
_081FC700:
	cmp r0, #0
	beq _081FC70C
	movs r0, #0x11
	adds r2, r3, #0
	adds r2, #0xa2
	strb r0, [r2]
_081FC70C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC71E
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r1, #1
	bl FUN_08022488
_081FC71E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fc724
FUN_081fc724: @ 0x081FC724
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC742
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r6, r1, #0
	b _081FC748
_081FC742:
	movs r0, #0
	adds r6, r4, #0
	adds r6, #0xa7
_081FC748:
	cmp r0, #0
	beq _081FC75E
	adds r0, r5, #0
	movs r1, #5
	movs r2, #0
	bl FUN_081fc890
	movs r0, #1
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
_081FC75E:
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r6]
	cmp r0, #0
	beq _081FC78A
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_081FC78A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc790
FUN_081fc790: @ 0x081FC790
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r1, r4, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC7AE
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	adds r6, r1, #0
	b _081FC7B4
_081FC7AE:
	movs r0, #0
	adds r6, r4, #0
	adds r6, #0xa7
_081FC7B4:
	cmp r0, #0
	beq _081FC7CA
	adds r0, r5, #0
	movs r1, #5
	movs r2, #0
	bl FUN_081fc890
	movs r0, #0x12
	adds r1, r4, #0
	adds r1, #0xa2
	strb r0, [r1]
_081FC7CA:
	movs r2, #0x10
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldrb r0, [r6]
	cmp r0, #0
	beq _081FC802
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_081FC802:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc808
FUN_081fc808: @ 0x081FC808
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FC822
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FC824
_081FC822:
	movs r0, #0
_081FC824:
	cmp r0, #0
	beq _081FC830
	movs r1, #0x13
	adds r0, r2, #0
	adds r0, #0xa2
	strb r1, [r0]
_081FC830:
	pop {r0}
	bx r0

	thumb_func_start FUN_081fc834
FUN_081fc834: @ 0x081FC834
	push {lr}
	ldr r2, _081FC84C @ =0x085AE630
	adds r1, r0, #0
	adds r1, #0xa6
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_081FC84C: .4byte 0x085AE630

	thumb_func_start FUN_081fc850
FUN_081fc850: @ 0x081FC850
	push {lr}
	ldr r2, _081FC868 @ =0x085AE654
	adds r1, r0, #0
	adds r1, #0xa5
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_081FC868: .4byte 0x085AE654

	thumb_func_start FUN_081fc86c
FUN_081fc86c: @ 0x081FC86C
	push {lr}
	adds r2, r0, #0
	adds r2, #0x9d
	movs r1, #0
	strb r1, [r2]
	ldr r2, _081FC88C @ =0x085AE658
	adds r1, r0, #0
	adds r1, #0xa4
	ldrb r1, [r1]
	lsls r1, r1, #2
	adds r1, r1, r2
	ldr r1, [r1]
	bl _call_via_r1
	pop {r0}
	bx r0
	.align 2, 0
_081FC88C: .4byte 0x085AE658

	thumb_func_start FUN_081fc890
FUN_081fc890: @ 0x081FC890
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x48
	ldr r3, _081FC8E8 @ =0x00000808
	adds r0, r6, r3
	adds r5, r6, #0
	adds r5, #0x50
	ldr r3, [r6, #0x50]
	ldr r4, [r6, #0x54]
	str r3, [r0]
	str r4, [r0, #4]
	ldr r0, _081FC8EC @ =0x00000806
	adds r3, r6, r0
	strb r1, [r3]
	ldr r1, _081FC8F0 @ =0x00000807
	adds r0, r6, r1
	strb r2, [r0]
	ldrb r1, [r3]
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_08234f90
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FC8E4
	cmp r1, #0
	blt _081FC8E4
	ldr r0, _081FC8F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FC8E4
	ldr r0, _081FC8F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FC8FC
_081FC8E4:
	movs r4, #0
	b _081FC90A
	.align 2, 0
_081FC8E8: .4byte 0x00000808
_081FC8EC: .4byte 0x00000806
_081FC8F0: .4byte 0x00000807
_081FC8F4: .4byte 0x030046A8
_081FC8F8: .4byte 0x030046AC
_081FC8FC:
	ldr r0, _081FC91C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FC90A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FC920
	adds r0, #4
	b _081FC92C
	.align 2, 0
_081FC91C: .4byte 0x030046A4
_081FC920:
	ldr r0, _081FC968 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FC92C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r3, #0
	strh r0, [r5, #2]
	mov r2, sp
	movs r1, #0xf0
	lsls r1, r1, #3
	mov r0, sp
	strh r1, [r0]
	strh r3, [r2, #2]
	strh r1, [r2, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r2, #0
	blt _081FC962
	ldr r0, _081FC96C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FC962
	ldr r0, _081FC970 @ =0x030046AC
	ldr r1, [r0]
	movs r0, #7
	cmp r0, r1
	blo _081FC974
_081FC962:
	movs r4, #0
	b _081FC97C
	.align 2, 0
_081FC968: .4byte 0x030046A4
_081FC96C: .4byte 0x030046A8
_081FC970: .4byte 0x030046AC
_081FC974:
	ldr r0, _081FC98C @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, r2
_081FC97C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FC990
	adds r0, #4
	b _081FC99C
	.align 2, 0
_081FC98C: .4byte 0x030046A4
_081FC990:
	ldr r0, _081FC9FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FC99C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r1, sp
	strh r0, [r1, #2]
	mov r2, sp
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #8
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0xc
	ldrsh r2, [r7, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FC9FC: .4byte 0x030046A4

	thumb_func_start FUN_081fca00
FUN_081fca00: @ 0x081FCA00
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FCA34
	movs r0, #0
	strb r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_08022c9c
_081FCA34:
	adds r0, r4, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r5, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081FCAFC
	adds r0, r4, #0
	adds r0, #0x4d
	add r3, sp, #0xc
	ldrb r5, [r0]
	movs r6, #0x5a
	rsbs r6, r6, #0
	ldr r2, _081FCA74 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081FCA78
	asrs r1, r0, #0xc
	b _081FCA7E
	.align 2, 0
_081FCA74: .4byte 0x085B0A08
_081FCA78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FCA7E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081FCA96
	asrs r0, r0, #0xc
	b _081FCA9C
_081FCA96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FCA9C:
	strh r0, [r3, #4]
	add r3, sp, #0xc
	adds r2, r4, #0
	adds r2, #0x50
	adds r1, r3, #0
	ldrh r0, [r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	ldr r2, _081FCAE8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FCAEC @ =0x000003FF
	ands r0, r1
	adds r0, #1
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FCAF0 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FCAF4
	adds r0, r4, #0
	movs r1, #0xb4
	bl FUN_081fad7c
	b _081FCAFC
	.align 2, 0
_081FCAE8: .4byte 0x030046B8
_081FCAEC: .4byte 0x000003FF
_081FCAF0: .4byte 0x0203B400
_081FCAF4:
	adds r0, r4, #0
	movs r1, #0x96
	bl FUN_081fabc0
_081FCAFC:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	adds r0, r4, #0
	bl FUN_08022dfc
	adds r1, r4, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fcb1c
FUN_081fcb1c: @ 0x081FCB1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	adds r5, r0, #0
	mov r8, r5
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r5
	mov sl, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FCC28
	movs r3, #0
	strb r3, [r1]
	movs r2, #0x14
	subs r1, #0x11
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add r0, sp, #0x3c
	movs r1, #0xf0
	lsls r1, r1, #3
	strh r1, [r0]
	strh r3, [r0, #2]
	strh r1, [r0, #4]
	adds r6, r0, #0
	movs r1, #7
	adds r7, r6, #0
	ldr r0, _081FCB74 @ =0x030046A8
	ldr r0, [r0]
	cmp r1, r0
	bhs _081FCB6E
	ldr r0, _081FCB78 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FCB7C
_081FCB6E:
	movs r4, #0
	b _081FCB84
	.align 2, 0
_081FCB74: .4byte 0x030046A8
_081FCB78: .4byte 0x030046AC
_081FCB7C:
	ldr r0, _081FCB94 @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, #7
_081FCB84:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FCB98
	adds r0, #4
	b _081FCBA4
	.align 2, 0
_081FCB94: .4byte 0x030046A4
_081FCB98:
	ldr r0, _081FCC3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FCBA4:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	adds r2, r5, #0
	adds r2, #0x50
	add r0, sp, #0x3c
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08022c9c
	mov r0, sl
	bl FUN_081fa590
	mov r0, sl
	movs r1, #1
	bl FUN_081fa5a0
_081FCC28:
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #1
	bne _081FCC32
	b _081FCE44
_081FCC32:
	cmp r0, #1
	bgt _081FCC40
	cmp r0, #0
	beq _081FCC4E
	b _081FCF3E
	.align 2, 0
_081FCC3C: .4byte 0x030046A4
_081FCC40:
	cmp r0, #2
	bne _081FCC46
	b _081FCEC2
_081FCC46:
	cmp r0, #3
	bne _081FCC4C
	b _081FCF1C
_081FCC4C:
	b _081FCF3E
_081FCC4E:
	movs r2, #0x14
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add r4, sp, #0x44
	adds r2, r5, #0
	adds r2, #0x50
	ldr r3, _081FCCB4 @ =0x00000808
	add r3, r8
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r6, #0x1e
	movs r2, #0
	ldrsh r0, [r4, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r7, r1, r0
	adds r0, r7, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081FCCB8
	movs r1, #1
	rsbs r1, r1, #0
	b _081FCCE4
	.align 2, 0
_081FCCB4: .4byte 0x00000808
_081FCCB8:
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
	adds r1, r7, #0
_081FCCE4:
	ldr r0, _081FCCF4 @ =0x0000038B
	cmp r1, r0
	bgt _081FCCF8
	mov r0, sl
	movs r1, #1
	bl FUN_081fa5a0
	b _081FCE2E
	.align 2, 0
_081FCCF4: .4byte 0x0000038B
_081FCCF8:
	mov r3, sl
	ldr r0, [r3, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _081FCD06
	b _081FCE2E
_081FCD06:
	ldr r5, _081FCD4C @ =0x00000808
	add r5, r8
	add r0, sp, #0x44
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
	ldr r6, _081FCD50 @ =0x030046B8
	ldr r0, [r6]
	adds r0, #1
	ldr r1, _081FCD54 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _081FCD58 @ =0x0203B400
	adds r0, r0, r2
	movs r3, #0xff
	mov sb, r3
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FCD5C
	adds r0, r5, #0
	bl FUN_081fae7c
	b _081FCE2E
	.align 2, 0
_081FCD4C: .4byte 0x00000808
_081FCD50: .4byte 0x030046B8
_081FCD54: .4byte 0x000003FF
_081FCD58: .4byte 0x0203B400
_081FCD5C:
	add r4, sp, #0x4c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FCDAC @ =0x05000002
	bl CpuSet
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	lsls r1, r0, #1
	ldr r2, _081FCDB0 @ =0x0203B400
	adds r1, r1, r2
	ldrh r7, [r1]
	mov r3, sb
	ands r7, r3
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r6, [r0]
	ands r6, r3
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [sp, #0x54]
	str r1, [sp, #0x58]
	ldr r1, _081FCDB4 @ =0x085B0A08
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081FCDB8
	asrs r0, r0, #0xc
	b _081FCDBE
	.align 2, 0
_081FCDAC: .4byte 0x05000002
_081FCDB0: .4byte 0x0203B400
_081FCDB4: .4byte 0x085B0A08
_081FCDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FCDBE:
	add r3, sp, #0x54
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081FCDE8 @ =0xFFFF0000
	ldr r0, [sp, #0x54]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x54]
	ldr r1, _081FCDEC @ =0x085B0A08
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r5, r3, #0
	cmp r0, #0
	blt _081FCDF0
	asrs r1, r0, #0xc
	b _081FCDF6
	.align 2, 0
_081FCDE8: .4byte 0xFFFF0000
_081FCDEC: .4byte 0x085B0A08
_081FCDF0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FCDF6:
	ldrh r0, [r5, #4]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r5, #4]
	ldr r2, _081FCE38 @ =0x00002E78
	ldr r3, _081FCE3C @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	str r1, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _081FCE40 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081f22c0
_081FCE2E:
	mov r2, sl
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	b _081FCF3E
	.align 2, 0
_081FCE38: .4byte 0x00002E78
_081FCE3C: .4byte 0x000038E2
_081FCE40: .4byte 0x00000232
_081FCE44:
	mov r3, sl
	ldr r0, [r3, #4]
	adds r0, #1
	str r0, [r3, #4]
	cmp r0, #0x78
	bls _081FCE58
	mov r0, sl
	movs r1, #2
	bl FUN_081fa5a0
_081FCE58:
	mov r0, sl
	ldr r1, [r0, #4]
	cmp r1, #0x5a
	bls _081FCEA0
	movs r0, #0xf
	ands r1, r0
	cmp r1, #0
	bne _081FCEA0
	ldr r2, _081FCE8C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FCE90 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FCE94 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FCE98
	adds r0, r5, #0
	movs r1, #0xb4
	bl FUN_081fad7c
	b _081FCEA0
	.align 2, 0
_081FCE8C: .4byte 0x030046B8
_081FCE90: .4byte 0x000003FF
_081FCE94: .4byte 0x0203B400
_081FCE98:
	adds r0, r5, #0
	movs r1, #0x50
	bl FUN_081fabc0
_081FCEA0:
	mov r2, sl
	ldr r0, [r2, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081FCEB4
	adds r0, r5, #0
	adds r0, #0x50
	bl FUN_081fae7c
_081FCEB4:
	movs r2, #0x14
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081FCF3E
_081FCEC2:
	mov r3, sl
	ldr r0, [r3, #4]
	adds r4, r5, #0
	adds r4, #0x98
	cmp r0, #0
	bne _081FCF04
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081fa628
	movs r1, #0x11
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_08022c9c
	ldr r0, _081FCF18 @ =0x000001B7
	bl PlaySound_082406e0
_081FCF04:
	movs r1, #4
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	mov r0, sl
	movs r1, #3
	bl FUN_081fa5a0
	b _081FCF3E
	.align 2, 0
_081FCF18: .4byte 0x000001B7
_081FCF1C:
	adds r0, r5, #0
	adds r0, #0xa7
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _081FCF50 @ =FUN_081fca00
	movs r0, #2
	adds r4, r5, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_081FCF3E:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FCF50: .4byte FUN_081fca00

	thumb_func_start FUN_081fcf54
FUN_081fcf54: @ 0x081FCF54
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FCF8A
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081fa628
	ldr r1, _081FCFA4 @ =0x000007FA
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _081FCFA8 @ =0x000007FC
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, _081FCFAC @ =0x000007CC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_08203d38
	ldr r0, _081FCFB0 @ =0x000001B7
	bl PlaySound_082406e0
_081FCF8A:
	movs r2, #0x14
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0xf
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081FCFA4: .4byte 0x000007FA
_081FCFA8: .4byte 0x000007FC
_081FCFAC: .4byte 0x000007CC
_081FCFB0: .4byte 0x000001B7

	thumb_func_start FUN_081fcfb4
FUN_081fcfb4: @ 0x081FCFB4
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FCFDC
	movs r0, #0
	strb r0, [r1]
	ldr r1, _081FCFF4 @ =0x000007FA
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _081FCFF8 @ =0x000007FC
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, _081FCFFC @ =0x000007CC
	adds r0, r4, r1
	ldr r0, [r0]
	bl FUN_08203d38
_081FCFDC:
	movs r2, #0x14
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0xf
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081FCFF4: .4byte 0x000007FA
_081FCFF8: .4byte 0x000007FC
_081FCFFC: .4byte 0x000007CC

	thumb_func_start FUN_081fd000
FUN_081fd000: @ 0x081FD000
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r7, r5, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FD09C
	movs r0, #0
	strb r0, [r1]
	mov r0, r8
	bl FUN_081fa590
	mov r0, r8
	movs r1, #0
	bl FUN_081fa5a0
	ldr r1, _081FD07C @ =0x000007CC
	adds r0, r5, r1
	ldr r0, [r0]
	bl FUN_08203d38
	ldr r2, _081FD080 @ =0x000007FA
	adds r0, r5, r2
	ldrh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _081FD084 @ =0x000007C9
	adds r0, r5, r1
	strb r2, [r0]
	subs r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_081fa620
	ldr r2, _081FD088 @ =0x000007CA
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081fa620
	adds r1, r0, #0
	cmp r1, #0
	bne _081FD08C
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r5, r2
	b _081FD09A
	.align 2, 0
_081FD07C: .4byte 0x000007CC
_081FD080: .4byte 0x000007FA
_081FD084: .4byte 0x000007C9
_081FD088: .4byte 0x000007CA
_081FD08C:
	ldr r0, _081FD0B0 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r1, r5, r2
_081FD09A:
	str r0, [r1]
_081FD09C:
	mov r0, r8
	ldrb r6, [r0]
	cmp r6, #1
	beq _081FD15C
	cmp r6, #1
	bgt _081FD0B4
	cmp r6, #0
	beq _081FD0BC
	b _081FD1F8
	.align 2, 0
_081FD0B0: .4byte 0x03003584
_081FD0B4:
	cmp r6, #2
	bne _081FD0BA
	b _081FD1C4
_081FD0BA:
	b _081FD1F8
_081FD0BC:
	mov r1, r8
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FD0E6
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	movs r3, #0xa
	bl FUN_08022c9c
	mov r1, r8
	str r4, [r1, #4]
_081FD0E6:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sb, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_08022dfc
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FD126
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	movs r3, #2
	bl FUN_08022c9c
	mov r0, r8
	movs r1, #1
	bl FUN_081fa5a0
_081FD126:
	ldr r2, _081FD150 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FD154 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FD158 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	asrs r0, r0, #1
	cmp r0, #0
	beq _081FD1F8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_081fa628
	b _081FD1F8
	.align 2, 0
_081FD150: .4byte 0x030046B8
_081FD154: .4byte 0x000003FF
_081FD158: .4byte 0x0203B400
_081FD15C:
	mov r2, r8
	ldr r3, [r2, #4]
	cmp r3, #0
	bne _081FD182
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	str r6, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0xc
	bl FUN_08022c9c
	mov r1, r8
	str r6, [r1, #4]
_081FD182:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r2, r2, r7
	mov sb, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r4, r7, r0
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	bl FUN_08022dfc
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FD1F8
	movs r0, #2
	str r0, [sp]
	str r6, [sp, #4]
	movs r0, #4
	str r0, [sp, #8]
	adds r0, r5, #0
	mov r1, sb
	adds r2, r4, #0
	movs r3, #0
	bl FUN_08022c9c
	mov r0, r8
	movs r1, #2
	bl FUN_081fa5a0
	b _081FD1F8
_081FD1C4:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r7, r0
	adds r0, r5, #0
	bl FUN_08022dfc
	adds r0, r5, #0
	adds r0, #0xa7
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _081FD208 @ =FUN_081fcf54
	movs r0, #3
	adds r4, r5, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_081FD1F8:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FD208: .4byte FUN_081fcf54

	thumb_func_start FUN_081fd20c
FUN_081fd20c: @ 0x081FD20C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	adds r6, r0, #0
	adds r7, r6, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x48]
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FD294
	movs r0, #0
	strb r0, [r1]
	ldr r0, [sp, #0x48]
	bl FUN_081fa590
	ldr r0, _081FD2B4 @ =0x03002BE0
	ldr r2, [r0]
	adds r3, r6, #0
	adds r3, #0x50
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r4, #0
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	movs r5, #0x30
	ldrsh r1, [r2, r5]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r6, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r6, #0
	adds r0, #0xa1
	strb r1, [r0]
	ldr r5, _081FD2B8 @ =0x000007CC
	adds r0, r6, r5
	ldr r0, [r0]
	movs r1, #2
	bl FUN_08203d0c
_081FD294:
	adds r0, r6, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r1, [sp, #0x48]
	ldrb r0, [r1]
	cmp r0, #8
	bls _081FD2AA
	b _081FD7EA
_081FD2AA:
	lsls r0, r0, #2
	ldr r1, _081FD2BC @ =_081FD2C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FD2B4: .4byte 0x03002BE0
_081FD2B8: .4byte 0x000007CC
_081FD2BC: .4byte _081FD2C0
_081FD2C0: @ jump table
	.4byte _081FD2E4 @ case 0
	.4byte _081FD314 @ case 1
	.4byte _081FD336 @ case 2
	.4byte _081FD358 @ case 3
	.4byte _081FD73A @ case 4
	.4byte _081FD75A @ case 5
	.4byte _081FD794 @ case 6
	.4byte _081FD7D0 @ case 7
	.4byte _081FD7E2 @ case 8
_081FD2E4:
	ldr r2, [sp, #0x48]
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FD30C
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r7, r4
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #2
_081FD304:
	bl FUN_08022c9c
	ldr r5, [sp, #0x48]
	str r4, [r5, #4]
_081FD30C:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	b _081FD7C4
_081FD314:
	ldr r4, [sp, #0x48]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD30C
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #4
	b _081FD304
_081FD336:
	ldr r4, [sp, #0x48]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD30C
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #6
	b _081FD304
_081FD358:
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r7, r4
	movs r5, #0x87
	lsls r5, r5, #2
	adds r2, r7, r5
	adds r0, r6, #0
	bl FUN_08022dfc
	ldr r1, [sp, #0x48]
	ldrb r0, [r1, #1]
	cmp r0, #1
	bne _081FD374
	b _081FD584
_081FD374:
	cmp r0, #1
	bgt _081FD37E
	cmp r0, #0
	beq _081FD386
	b _081FD7EA
_081FD37E:
	cmp r0, #2
	bne _081FD384
	b _081FD614
_081FD384:
	b _081FD7EA
_081FD386:
	adds r2, r6, #0
	adds r2, #0x4d
	ldrb r0, [r2]
	subs r0, #0x40
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x40
	ldrb r0, [r2]
	subs r0, #0x20
	ands r0, r1
	adds r3, r0, #0
	adds r3, #0x40
	add r5, sp, #0x28
	ldr r2, _081FD3C8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	mov r8, r2
	cmp r0, #0
	blt _081FD3CC
	asrs r1, r0, #0xc
	b _081FD3D2
	.align 2, 0
_081FD3C8: .4byte 0x085B0A08
_081FD3CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD3D2:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081FD3F2
	asrs r0, r0, #0xc
	b _081FD3F8
_081FD3F2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FD3F8:
	strh r0, [r5, #4]
	add r4, sp, #0x30
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #8
	cmp r0, #0
	blt _081FD416
	asrs r1, r0, #0xc
	b _081FD41C
_081FD416:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD41C:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081FD43C
	asrs r0, r0, #0xc
	b _081FD442
_081FD43C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FD442:
	movs r2, #0
	strh r0, [r4, #4]
	add r0, sp, #0x38
	movs r1, #0xf0
	lsls r1, r1, #3
	strh r1, [r0]
	strh r2, [r0, #2]
	strh r1, [r0, #4]
	adds r5, r0, #0
	movs r1, #7
	mov r8, r5
	ldr r0, _081FD46C @ =0x030046A8
	ldr r0, [r0]
	cmp r1, r0
	bhs _081FD468
	ldr r0, _081FD470 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FD474
_081FD468:
	movs r4, #0
	b _081FD47C
	.align 2, 0
_081FD46C: .4byte 0x030046A8
_081FD470: .4byte 0x030046AC
_081FD474:
	ldr r0, _081FD48C @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, #7
_081FD47C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FD490
	adds r0, #4
	b _081FD49C
	.align 2, 0
_081FD48C: .4byte 0x030046A4
_081FD490:
	ldr r0, _081FD548 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FD49C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	movs r3, #0x82
	lsls r3, r3, #4
	adds r6, r7, r3
	add r1, sp, #0x28
	add r0, sp, #0x38
	ldrh r5, [r0]
	adds r0, r1, #0
	ldrh r0, [r0]
	mov sl, r0
	mov r4, sl
	adds r0, r5, r4
	strh r0, [r6]
	mov r0, r8
	ldrh r4, [r0, #2]
	ldrh r2, [r1, #2]
	mov sb, r2
	mov r3, sb
	adds r0, r4, r3
	strh r0, [r6, #2]
	mov r0, r8
	ldrh r3, [r0, #4]
	ldrh r1, [r1, #4]
	mov r8, r1
	mov r1, r8
	adds r0, r3, r1
	strh r0, [r6, #4]
	ldr r0, _081FD54C @ =0x00000828
	adds r2, r7, r0
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #4
	adds r0, r7, r1
	mov r2, sl
	subs r5, r5, r2
	strh r5, [r0]
	mov r5, sb
	subs r4, r4, r5
	strh r4, [r0, #2]
	mov r1, r8
	subs r3, r3, r1
	strh r3, [r0, #4]
	ldr r2, _081FD550 @ =0x030046B8
	add r4, sp, #0x30
	adds r5, r4, #0
	movs r7, #2
_081FD506:
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FD554 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081FD558 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #3
	str r2, [sp, #0x4c]
	bl Mod
	ldr r2, [sp, #0x4c]
	cmp r0, #1
	beq _081FD55C
	cmp r0, #1
	bgt _081FD574
	cmp r0, #0
	bne _081FD574
	ldrh r0, [r5]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	ldrh r0, [r4, #2]
	ldrh r3, [r6, #2]
	adds r0, r0, r3
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	b _081FD572
	.align 2, 0
_081FD548: .4byte 0x030046A4
_081FD54C: .4byte 0x00000828
_081FD550: .4byte 0x030046B8
_081FD554: .4byte 0x000003FF
_081FD558: .4byte 0x0203B400
_081FD55C:
	ldrh r0, [r6]
	ldrh r1, [r5]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
_081FD572:
	strh r0, [r6, #4]
_081FD574:
	adds r6, #8
	subs r7, #1
	cmp r7, #0
	bge _081FD506
	ldr r0, [sp, #0x48]
	bl FUN_081fa5dc
	b _081FD7EA
_081FD584:
	adds r0, r6, #0
	adds r0, #0x50
	ldr r2, [sp, #0x48]
	ldr r1, [r2, #4]
	lsls r1, r1, #3
	movs r3, #0x82
	lsls r3, r3, #4
	adds r1, r1, r3
	adds r1, r7, r1
	ldr r4, _081FD600 @ =0x000007F6
	adds r2, r7, r4
	ldrh r2, [r2]
	ldr r5, _081FD604 @ =0x000007EC
	adds r3, r7, r5
	movs r5, #0
	ldrsh r4, [r3, r5]
	mov r8, r4
	movs r4, #0xf
	str r4, [sp]
	movs r6, #2
	str r6, [sp, #4]
	movs r5, #0xa
	str r5, [sp, #8]
	ldr r4, _081FD608 @ =0x00000BB8
	str r4, [sp, #0xc]
	movs r4, #0x12
	str r4, [sp, #0x10]
	ldr r3, _081FD60C @ =0x000007EE
	adds r3, r3, r7
	mov sb, r3
	movs r4, #0
	ldrsh r3, [r3, r4]
	str r3, [sp, #0x14]
	movs r4, #5
	str r4, [sp, #0x18]
	str r6, [sp, #0x1c]
	str r5, [sp, #0x20]
	movs r4, #0x96
	lsls r4, r4, #2
	str r4, [sp, #0x24]
	mov r3, r8
	bl FUN_0820361c
	movs r0, #0xdc
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r5, [sp, #0x48]
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	ldr r0, [sp, #0x48]
	bl FUN_081fa5dc
	ldr r1, _081FD610 @ =0x000007CC
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08203c4c
	b _081FD7EA
	.align 2, 0
_081FD600: .4byte 0x000007F6
_081FD604: .4byte 0x000007EC
_081FD608: .4byte 0x00000BB8
_081FD60C: .4byte 0x000007EE
_081FD610: .4byte 0x000007CC
_081FD614:
	ldr r2, _081FD64C @ =0x000007CC
	adds r4, r7, r2
	ldr r0, [r4]
	movs r1, #1
	bl FUN_08203c4c
	ldr r3, [sp, #0x48]
	ldr r0, [r3, #8]
	adds r5, r0, #1
	str r5, [r3, #8]
	movs r1, #0xff
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r5, r0
	bls _081FD65A
	ldr r0, [r4]
	movs r1, #1
	bl FUN_08203c58
	ldr r2, [sp, #0x48]
	ldr r0, [r2, #4]
	cmp r0, #2
	bls _081FD650
	adds r0, r2, #0
	bl FUN_081fa5b0
	b _081FD7EA
	.align 2, 0
_081FD64C: .4byte 0x000007CC
_081FD650:
	ldr r0, [sp, #0x48]
	movs r1, #1
	bl FUN_081fa5d0
	b _081FD7EA
_081FD65A:
	cmp r5, #1
	bne _081FD6B4
	adds r0, r6, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	movs r3, #0xc0
	lsls r3, r3, #0x18
	adds r0, r0, r3
	add r4, sp, #0x40
	lsrs r5, r0, #0x18
	movs r7, #0x3c
	rsbs r7, r7, #0
	ldr r2, _081FD694 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	mov r8, r2
	adds r2, r4, #0
	cmp r0, #0
	blt _081FD698
	asrs r1, r0, #0xc
	b _081FD69E
	.align 2, 0
_081FD694: .4byte 0x085B0A08
_081FD698:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD69E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	bge _081FD70E
	b _081FD712
_081FD6B4:
	cmp r5, #9
	bls _081FD6BA
	b _081FD7EA
_081FD6BA:
	adds r0, r6, #0
	adds r0, #0xa0
	ldrb r0, [r0]
	lsls r0, r0, #0x1e
	movs r3, #0xc0
	lsls r3, r3, #0x18
	adds r0, r0, r3
	add r4, sp, #0x40
	lsrs r5, r0, #0x18
	movs r7, #6
	ldr r2, _081FD6F0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	mov r8, r2
	adds r2, r4, #0
	cmp r0, #0
	blt _081FD6F4
	asrs r1, r0, #0xc
	b _081FD6FA
	.align 2, 0
_081FD6F0: .4byte 0x085B0A08
_081FD6F4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FD6FA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	add r0, r8
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _081FD712
_081FD70E:
	asrs r0, r0, #0xc
	b _081FD718
_081FD712:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FD718:
	strh r0, [r4, #4]
	adds r1, r6, #0
	adds r1, #0x50
	add r0, sp, #0x40
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r5, [r1, #2]
	adds r0, r0, r5
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	b _081FD7EA
_081FD73A:
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r7, r4
	adds r0, r6, #0
	bl FUN_08022dfc
	ldr r5, [sp, #0x48]
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0x64
	bls _081FD7EA
	b _081FD7DA
_081FD75A:
	ldr r1, [sp, #0x48]
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FD7BE
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #4
	bl FUN_08022c9c
	ldr r5, [sp, #0x48]
	str r4, [r5, #4]
	ldr r1, _081FD790 @ =0x000007CC
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_08203d38
	b _081FD7BE
	.align 2, 0
_081FD790: .4byte 0x000007CC
_081FD794:
	ldr r4, [sp, #0x48]
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD7BE
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r3, #2
	bl FUN_08022c9c
	ldr r1, [sp, #0x48]
	str r4, [r1, #4]
_081FD7BE:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r7, r2
_081FD7C4:
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r7, r3
	adds r0, r6, #0
	bl FUN_08022dfc
_081FD7D0:
	adds r0, r6, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FD7EA
_081FD7DA:
	ldr r0, [sp, #0x48]
	bl FUN_081fa5b0
	b _081FD7EA
_081FD7E2:
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FD7EA:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fd7fc
FUN_081fd7fc: @ 0x081FD7FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	adds r5, r0, #0
	adds r6, r5, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r5
	mov r8, r0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FD8E6
	movs r3, #0
	strb r3, [r1]
	add r2, sp, #0x14
	movs r1, #0xf0
	lsls r1, r1, #3
	adds r0, r2, #0
	strh r1, [r0]
	strh r3, [r2, #2]
	strh r1, [r2, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r2, #0
	blt _081FD84C
	ldr r0, _081FD850 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FD84C
	ldr r0, _081FD854 @ =0x030046AC
	ldr r1, [r0]
	movs r0, #7
	cmp r0, r1
	blo _081FD858
_081FD84C:
	movs r4, #0
	b _081FD860
	.align 2, 0
_081FD850: .4byte 0x030046A8
_081FD854: .4byte 0x030046AC
_081FD858:
	ldr r0, _081FD870 @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, r2
_081FD860:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FD874
	adds r0, #4
	b _081FD880
	.align 2, 0
_081FD870: .4byte 0x030046A4
_081FD874:
	ldr r0, _081FD908 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FD880:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	add r1, sp, #0x14
	strh r0, [r1, #2]
	adds r2, r5, #0
	adds r2, #0x50
	adds r3, r1, #0
	adds r0, r1, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r3, r4]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r5, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r6, r4
	bl FUN_081fa590
_081FD8E6:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #8
	bls _081FD8FC
	b _081FDD08
_081FD8FC:
	lsls r0, r0, #2
	ldr r1, _081FD90C @ =_081FD910
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FD908: .4byte 0x030046A4
_081FD90C: .4byte _081FD910
_081FD910: @ jump table
	.4byte _081FD934 @ case 0
	.4byte _081FD980 @ case 1
	.4byte _081FD9D0 @ case 2
	.4byte _081FDA0A @ case 3
	.4byte _081FDC12 @ case 4
	.4byte _081FDC5C @ case 5
	.4byte _081FDCA8 @ case 6
	.4byte _081FDCE6 @ case 7
	.4byte _081FDD00 @ case 8
_081FD934:
	mov r2, r8
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FD968
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #2
	bl FUN_08022c9c
	mov r0, r8
	str r4, [r0, #4]
	ldr r1, _081FD97C @ =0x000007CC
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08203d0c
_081FD968:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl FUN_08022dfc
	b _081FDCEE
	.align 2, 0
_081FD97C: .4byte 0x000007CC
_081FD980:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD9A8
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #4
	bl FUN_08022c9c
	mov r0, r8
	str r4, [r0, #4]
_081FD9A8:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl FUN_08022dfc
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FD9C6
	b _081FDD08
_081FD9C6:
	mov r0, r8
	movs r1, #2
	bl FUN_081fa5a0
	b _081FDD08
_081FD9D0:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FD9F6
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #8
	bl FUN_08022c34
	mov r0, r8
	str r4, [r0, #4]
_081FD9F6:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl FUN_08022dfc
	b _081FDCEE
_081FDA0A:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FDA36
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #9
	bl FUN_08022c34
	mov r0, r8
	str r4, [r0, #4]
	ldr r0, _081FDAB0 @ =0x000001B9
	bl PlaySound_082406e0
_081FDA36:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl FUN_08022dfc
	ldr r0, _081FDAB4 @ =0x03002BE0
	ldr r2, [r0]
	adds r4, r5, #0
	adds r4, #0x50
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
	subs r3, #0x1f
	ldr r2, _081FDAB8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FDABC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FDAC0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r3, r3, r0
	add r7, sp, #0x1c
	movs r2, #0xa
	mov ip, r2
	ldr r2, _081FDAC4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	mov sl, r7
	cmp r0, #0
	blt _081FDAC8
	asrs r1, r0, #0xc
	b _081FDACE
	.align 2, 0
_081FDAB0: .4byte 0x000001B9
_081FDAB4: .4byte 0x03002BE0
_081FDAB8: .4byte 0x030046B8
_081FDABC: .4byte 0x000003FF
_081FDAC0: .4byte 0x0203B400
_081FDAC4: .4byte 0x085B0A08
_081FDAC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FDACE:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _081FDAF4 @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	mov sb, r1
	cmp r0, #0
	blt _081FDAF8
	asrs r0, r0, #0xc
	b _081FDAFE
	.align 2, 0
_081FDAF4: .4byte 0x085B0A08
_081FDAF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FDAFE:
	strh r0, [r7, #4]
	ldr r0, _081FDB48 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081FDBFE
	ldr r2, _081FDB4C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FDB50 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081FDB54 @ =0x0203B400
	adds r0, r0, r3
	movs r1, #0xff
	ldrb r0, [r0]
	mov ip, r0
	adds r0, r5, #0
	adds r0, #0x4d
	add r3, sp, #0x24
	ldrb r2, [r0]
	movs r5, #0x50
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r7, r3, #0
	cmp r0, #0
	blt _081FDB58
	asrs r1, r0, #0xc
	b _081FDB5E
	.align 2, 0
_081FDB48: .4byte 0x03002CF0
_081FDB4C: .4byte 0x030046B8
_081FDB50: .4byte 0x000003FF
_081FDB54: .4byte 0x0203B400
_081FDB58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FDB5E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r2, #1
	add r0, sb
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FDB76
	asrs r0, r0, #0xc
	b _081FDB7C
_081FDB76:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FDB7C:
	strh r0, [r3, #4]
	ldrh r2, [r7]
	subs r2, #0x20
	add r5, sp, #0x24
	strh r2, [r5]
	adds r7, r5, #0
	ldrh r1, [r7, #2]
	ldrh r3, [r7, #4]
	ldrh r0, [r4]
	adds r2, r2, r0
	strh r2, [r7]
	adds r1, #0x20
	ldrh r0, [r4, #2]
	adds r1, r1, r0
	strh r1, [r7, #2]
	subs r3, #0x20
	ldrh r4, [r4, #4]
	adds r3, r3, r4
	strh r3, [r7, #4]
	mov r1, ip
	cmp r1, #0x7f
	bgt _081FDBCE
	movs r3, #0x96
	lsls r3, r3, #1
	movs r1, #0xa
	str r1, [sp]
	movs r2, #0xfd
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r7, #0
	mov r1, sl
	movs r2, #4
	b _081FDBF2
_081FDBCE:
	movs r3, #0x96
	lsls r3, r3, #1
	movs r1, #0xa
	str r1, [sp]
	movs r2, #0xfd
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	movs r0, #8
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #8
_081FDBF2:
	bl FUN_080df148
	mov r1, r8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
_081FDBFE:
	mov r2, r8
	ldr r0, [r2, #4]
	cmp r0, #0x1e
	bhi _081FDC08
	b _081FDD08
_081FDC08:
	mov r0, r8
	movs r1, #4
	bl FUN_081fa5a0
	b _081FDD08
_081FDC12:
	mov r3, r8
	ldr r0, [r3, #4]
	cmp r0, #0
	bne _081FDC3C
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #8
	bl FUN_08022c9c
	mov r1, r8
	str r4, [r1, #4]
_081FDC3C:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl FUN_08022dfc
	mov r4, r8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x64
	bls _081FDD08
	b _081FDCF8
_081FDC5C:
	mov r1, r8
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FDC90
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #4
	bl FUN_08022c9c
	mov r0, r8
	str r4, [r0, #4]
	ldr r1, _081FDCA4 @ =0x000007CC
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_08203d38
_081FDC90:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl FUN_08022dfc
	b _081FDCEE
	.align 2, 0
_081FDCA4: .4byte 0x000007CC
_081FDCA8:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FDCD2
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r5, #0
	movs r3, #2
	bl FUN_08022c9c
	mov r0, r8
	str r4, [r0, #4]
_081FDCD2:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r5, #0
	bl FUN_08022dfc
	b _081FDCEE
_081FDCE6:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081fa628
_081FDCEE:
	adds r0, r5, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FDD08
_081FDCF8:
	mov r0, r8
	bl FUN_081fa5b0
	b _081FDD08
_081FDD00:
	adds r1, r5, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FDD08:
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fdd18
FUN_081fdd18: @ 0x081FDD18
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	adds r6, r7, #0
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FDE02
	movs r3, #0
	strb r3, [r1]
	add r2, sp, #0x14
	movs r1, #0xf0
	lsls r1, r1, #3
	adds r0, r2, #0
	strh r1, [r0]
	strh r3, [r2, #2]
	strh r1, [r2, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	cmp r2, #0
	blt _081FDD66
	ldr r0, _081FDD6C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FDD66
	ldr r0, _081FDD70 @ =0x030046AC
	ldr r1, [r0]
	movs r0, #7
	cmp r0, r1
	blo _081FDD74
_081FDD66:
	movs r4, #0
	b _081FDD7C
	.align 2, 0
_081FDD6C: .4byte 0x030046A8
_081FDD70: .4byte 0x030046AC
_081FDD74:
	ldr r0, _081FDD8C @ =0x030046A4
	ldr r0, [r0]
	ldrh r0, [r0, #0x32]
	adds r4, r0, r2
_081FDD7C:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FDD90
	adds r0, #4
	b _081FDD9C
	.align 2, 0
_081FDD8C: .4byte 0x030046A4
_081FDD90:
	ldr r0, _081FDE24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FDD9C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	add r1, sp, #0x14
	strh r0, [r1, #2]
	adds r2, r7, #0
	adds r2, #0x50
	adds r3, r1, #0
	adds r0, r1, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r7, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	movs r4, #0x83
	lsls r4, r4, #2
	adds r0, r6, r4
	bl FUN_081fa590
_081FDE02:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	mov r5, r8
	ldrb r0, [r5]
	cmp r0, #0xc
	bls _081FDE18
	b _081FE2D0
_081FDE18:
	lsls r0, r0, #2
	ldr r1, _081FDE28 @ =_081FDE2C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FDE24: .4byte 0x030046A4
_081FDE28: .4byte _081FDE2C
_081FDE2C: @ jump table
	.4byte _081FDE60 @ case 0
	.4byte _081FDF24 @ case 1
	.4byte _081FDF76 @ case 2
	.4byte _081FDFBE @ case 3
	.4byte _081FE144 @ case 4
	.4byte _081FDFBE @ case 5
	.4byte _081FE144 @ case 6
	.4byte _081FDFBE @ case 7
	.4byte _081FE166 @ case 8
	.4byte _081FE1B0 @ case 9
	.4byte _081FE270 @ case 10
	.4byte _081FE2AE @ case 11
	.4byte _081FE2C8 @ case 12
_081FDE60:
	mov r0, r8
	ldr r5, [r0, #4]
	cmp r5, #0
	bne _081FDF08
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r5, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl FUN_08022c9c
	mov r0, r8
	str r4, [r0, #4]
	movs r1, #0xf9
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r4, [r0]
	ldr r2, _081FDEB0 @ =0x000007CA
	adds r4, r6, r2
	movs r1, #0
	strh r5, [r4]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _081FDED0
	cmp r0, #2
	bgt _081FDEB4
	cmp r0, #1
	beq _081FDEBA
	b _081FDEEC
	.align 2, 0
_081FDEB0: .4byte 0x000007CA
_081FDEB4:
	cmp r0, #3
	beq _081FDEDC
	b _081FDEEC
_081FDEBA:
	ldr r3, _081FDECC @ =0x000007C9
	adds r0, r6, r3
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_081fa620
	strh r0, [r4]
	b _081FDEF4
	.align 2, 0
_081FDECC: .4byte 0x000007C9
_081FDED0:
	ldr r2, _081FDED8 @ =0x000007C9
	adds r0, r6, r2
	b _081FDEE0
	.align 2, 0
_081FDED8: .4byte 0x000007C9
_081FDEDC:
	ldr r3, _081FDEE8 @ =0x000007C9
	adds r0, r6, r3
_081FDEE0:
	strb r1, [r0]
	strh r5, [r4]
	b _081FDEF4
	.align 2, 0
_081FDEE8: .4byte 0x000007C9
_081FDEEC:
	ldr r4, _081FDF1C @ =0x000007C9
	adds r1, r6, r4
	movs r0, #0
	strb r0, [r1]
_081FDEF4:
	movs r0, #0xdd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r5, _081FDF20 @ =0x000007CC
	adds r0, r6, r5
	ldr r0, [r0]
	movs r1, #1
	bl FUN_08203d0c
_081FDF08:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl FUN_08022dfc
	b _081FE2B6
	.align 2, 0
_081FDF1C: .4byte 0x000007C9
_081FDF20: .4byte 0x000007CC
_081FDF24:
	mov r4, r8
	ldr r3, [r4, #4]
	cmp r3, #0
	bne _081FDF4E
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r6, r5
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl FUN_08022c9c
	mov r1, r8
	str r4, [r1, #4]
_081FDF4E:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl FUN_08022dfc
	adds r0, r7, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FDF6C
	b _081FE2D0
_081FDF6C:
	mov r0, r8
	movs r1, #2
	bl FUN_081fa5a0
	b _081FE2D0
_081FDF76:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FDF9C
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r6, r5
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r3, #8
	bl FUN_08022c34
	mov r5, r8
	str r4, [r5, #4]
_081FDF9C:
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl FUN_08022dfc
	mov r4, r8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x3c
	bhi _081FDFBC
	b _081FE2D0
_081FDFBC:
	b _081FE2C0
_081FDFBE:
	mov r5, r8
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _081FDFCC
	ldr r0, _081FE020 @ =0x000001B9
	bl PlaySound_082406e0
_081FDFCC:
	mov r1, r8
	ldr r0, [r1, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _081FDFDA
	b _081FE118
_081FDFDA:
	ldr r2, _081FE024 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FE028 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FE02C @ =0x0203B400
	adds r0, r0, r2
	movs r2, #0xff
	ldrb r0, [r0]
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0x4d
	add r3, sp, #0x1c
	ldrb r5, [r0]
	movs r4, #0x50
	mov ip, r4
	ldr r1, _081FE030 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r4, ip
	muls r4, r0, r4
	adds r0, r4, #0
	adds r4, r3, #0
	adds r2, r1, #0
	cmp r0, #0
	blt _081FE034
	asrs r1, r0, #0xc
	b _081FE03A
	.align 2, 0
_081FE020: .4byte 0x000001B9
_081FE024: .4byte 0x030046B8
_081FE028: .4byte 0x000003FF
_081FE02C: .4byte 0x0203B400
_081FE030: .4byte 0x085B0A08
_081FE034:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE03A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FE056
	asrs r0, r0, #0xc
	b _081FE05C
_081FE056:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FE05C:
	strh r0, [r3, #4]
	ldrh r0, [r4]
	subs r0, #0x20
	add r1, sp, #0x1c
	strh r0, [r1]
	ldrh r0, [r1, #2]
	adds r0, #0x20
	strh r0, [r1, #2]
	ldrh r0, [r1, #4]
	subs r0, #0x20
	strh r0, [r1, #4]
	mov r3, sb
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r0, [r0, r5]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081FE086
	asrs r1, r0, #0xc
	b _081FE08C
_081FE086:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE08C:
	ldrh r0, [r4]
	adds r0, r0, r1
	add r1, sp, #0x1c
	strh r0, [r1]
	mov r0, sb
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	cmp r0, #0
	blt _081FE0AE
	asrs r1, r0, #0xc
	b _081FE0B4
_081FE0AE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE0B4:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r3, r7, #0
	adds r3, #0x50
	add r1, sp, #0x1c
	ldrh r0, [r3]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r5, [r4, #4]
	adds r0, r0, r5
	strh r0, [r4, #4]
	ldr r0, _081FE13C @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #0x30
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r1, r0, #0
	movs r0, #8
	str r0, [sp]
	movs r0, #0x20
	str r0, [sp, #4]
	ldr r2, _081FE140 @ =0x000007EA
	adds r0, r6, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	str r4, [sp, #0x10]
	movs r0, #1
	movs r2, #0
	movs r3, #0x10
	bl FUN_08056774
_081FE118:
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r5, #0x87
	lsls r5, r5, #2
	adds r2, r6, r5
	adds r0, r7, #0
	bl FUN_08022dfc
	mov r1, r8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x3c
	bhi _081FE138
	b _081FE2D0
_081FE138:
	b _081FE2C0
	.align 2, 0
_081FE13C: .4byte 0x03002BE0
_081FE140: .4byte 0x000007EA
_081FE144:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl FUN_08022dfc
	mov r4, r8
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
	cmp r0, #0x1e
	bhi _081FE164
	b _081FE2D0
_081FE164:
	b _081FE2C0
_081FE166:
	mov r5, r8
	ldr r0, [r5, #4]
	cmp r0, #0
	bne _081FE18E
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r4, #1
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #8
	bl FUN_08022c9c
	str r4, [r5, #4]
_081FE18E:
	movs r4, #0x8f
	lsls r4, r4, #2
	adds r1, r6, r4
	movs r5, #0x87
	lsls r5, r5, #2
	adds r2, r6, r5
	adds r0, r7, #0
	bl FUN_08022dfc
	mov r1, r8
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x64
	bhi _081FE1AE
	b _081FE2D0
_081FE1AE:
	b _081FE2C0
_081FE1B0:
	mov r2, r8
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FE258
	movs r3, #0x8f
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r4, #0x87
	lsls r4, r4, #2
	adds r2, r6, r4
	movs r4, #2
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl FUN_08022c9c
	mov r0, r8
	str r5, [r0, #4]
	ldr r1, _081FE20C @ =0x000007CC
	adds r0, r6, r1
	ldr r0, [r0]
	bl FUN_08203d38
	ldr r2, _081FE210 @ =0x00000233
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r4, [r0]
	ldr r5, _081FE214 @ =0x000007CA
	adds r4, r6, r5
	movs r1, #0
	strh r2, [r4]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #2
	beq _081FE234
	cmp r0, #2
	bgt _081FE218
	cmp r0, #1
	beq _081FE21E
	b _081FE250
	.align 2, 0
_081FE20C: .4byte 0x000007CC
_081FE210: .4byte 0x00000233
_081FE214: .4byte 0x000007CA
_081FE218:
	cmp r0, #3
	beq _081FE240
	b _081FE250
_081FE21E:
	ldr r2, _081FE230 @ =0x000007C9
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_081fa620
	strh r0, [r4]
	b _081FE258
	.align 2, 0
_081FE230: .4byte 0x000007C9
_081FE234:
	ldr r3, _081FE23C @ =0x000007C9
	adds r0, r6, r3
	b _081FE244
	.align 2, 0
_081FE23C: .4byte 0x000007C9
_081FE240:
	ldr r5, _081FE24C @ =0x000007C9
	adds r0, r6, r5
_081FE244:
	strb r1, [r0]
	strh r2, [r4]
	b _081FE258
	.align 2, 0
_081FE24C: .4byte 0x000007C9
_081FE250:
	ldr r0, _081FE26C @ =0x000007C9
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
_081FE258:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl FUN_08022dfc
	b _081FE2B6
	.align 2, 0
_081FE26C: .4byte 0x000007C9
_081FE270:
	mov r4, r8
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _081FE29A
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r1, r6, r5
	movs r0, #0x87
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl FUN_08022c9c
	mov r1, r8
	str r4, [r1, #4]
_081FE29A:
	movs r2, #0x8f
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x87
	lsls r3, r3, #2
	adds r2, r6, r3
	adds r0, r7, #0
	bl FUN_08022dfc
	b _081FE2B6
_081FE2AE:
	adds r0, r7, #0
	movs r1, #1
	bl FUN_081fa628
_081FE2B6:
	adds r0, r7, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FE2D0
_081FE2C0:
	mov r0, r8
	bl FUN_081fa5b0
	b _081FE2D0
_081FE2C8:
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FE2D0:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fe2e0
FUN_081fe2e0: @ 0x081FE2E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	adds r7, r0, #0
	mov r8, r7
	movs r0, #0x83
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0xa9
	ldrb r0, [r4]
	cmp r0, #0
	beq _081FE36A
	movs r0, #0
	strb r0, [r4]
	ldr r0, _081FE3B0 @ =0x03002BE0
	ldr r2, [r0]
	adds r3, r7, #0
	adds r3, #0x50
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #0x30
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r0, #0x40
	adds r3, r7, #0
	adds r3, #0x4d
	strb r0, [r3]
	ldrb r0, [r3]
	adds r0, #0x20
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa0
	strb r1, [r0]
	ldrb r0, [r3]
	adds r0, #0x10
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	adds r0, r7, #0
	adds r0, #0xa1
	strb r1, [r0]
	mov r0, sl
	bl FUN_081fa590
_081FE36A:
	adds r0, r7, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _081FE380
	b _081FEA6E
_081FE380:
	movs r5, #1
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	ands r0, r5
	str r1, [sp, #0x2c]
	cmp r0, #0
	beq _081FE3B8
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #2
	bhi _081FE3B8
	ldr r1, _081FE3B4 @ =FUN_081fd000
	movs r0, #5
	adds r2, r7, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	strb r5, [r4]
	b _081FEA6E
	.align 2, 0
_081FE3B0: .4byte 0x03002BE0
_081FE3B4: .4byte FUN_081fd000
_081FE3B8:
	mov r2, sl
	ldrb r0, [r2]
	cmp r0, #9
	bls _081FE3C2
	b _081FEA6E
_081FE3C2:
	lsls r0, r0, #2
	ldr r1, _081FE3CC @ =_081FE3D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FE3CC: .4byte _081FE3D0
_081FE3D0: @ jump table
	.4byte _081FE3F8 @ case 0
	.4byte _081FE424 @ case 1
	.4byte _081FE452 @ case 2
	.4byte _081FE584 @ case 3
	.4byte _081FE7C4 @ case 4
	.4byte _081FE800 @ case 5
	.4byte _081FE9DC @ case 6
	.4byte _081FEA18 @ case 7
	.4byte _081FEA54 @ case 8
	.4byte _081FEA66 @ case 9
_081FE3F8:
	mov r5, sl
	ldr r3, [r5, #4]
	cmp r3, #0
	beq _081FE402
	b _081FEA42
_081FE402:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl FUN_08022c9c
	str r4, [r5, #4]
	b _081FEA42
_081FE424:
	mov r0, sl
	ldr r3, [r0, #4]
	cmp r3, #0
	beq _081FE42E
	b _081FEA42
_081FE42E:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl FUN_08022c9c
	mov r1, sl
	str r4, [r1, #4]
	b _081FEA42
_081FE452:
	mov r2, sl
	ldr r3, [r2, #4]
	cmp r3, #0
	bne _081FE484
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r7, #0
	movs r3, #6
	bl FUN_08022c9c
	ldr r0, _081FE4CC @ =0x000007CC
	add r0, r8
	ldr r0, [r0]
	movs r1, #3
	bl FUN_08203d0c
_081FE484:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl FUN_08022dfc
	ldr r1, _081FE4D0 @ =0x000007F4
	add r1, r8
	mov r3, sl
	ldr r0, [r3, #4]
	ldrh r1, [r1]
	cmp r0, r1
	bls _081FE51E
	adds r0, r7, #0
	adds r0, #0x4d
	add r3, sp, #0xc
	ldrb r4, [r0]
	movs r5, #5
	rsbs r5, r5, #0
	ldr r2, _081FE4D4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FE4D8
	asrs r1, r0, #0xc
	b _081FE4DE
	.align 2, 0
_081FE4CC: .4byte 0x000007CC
_081FE4D0: .4byte 0x000007F4
_081FE4D4: .4byte 0x085B0A08
_081FE4D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FE4DE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081FE4F6
	asrs r0, r0, #0xc
	b _081FE4FC
_081FE4F6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FE4FC:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x50
	add r2, sp, #0xc
	adds r0, r2, #0
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r5, [r1, #2]
	adds r0, r0, r5
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
_081FE51E:
	mov r3, sl
	ldr r1, [r3, #4]
	movs r0, #7
	ands r1, r0
	cmp r1, #0
	beq _081FE52E
	cmp r1, #3
	bne _081FE56A
_081FE52E:
	ldr r2, _081FE554 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FE558 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _081FE55C @ =0x0203B400
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081FE560
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r7, #0
	bl FUN_081fad7c
	b _081FE56A
	.align 2, 0
_081FE554: .4byte 0x030046B8
_081FE558: .4byte 0x000003FF
_081FE55C: .4byte 0x0203B400
_081FE560:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r7, #0
	bl FUN_081fabc0
_081FE56A:
	mov r1, sl
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	ldr r1, _081FE580 @ =0x000007F2
	add r1, r8
	ldrh r1, [r1]
	cmp r0, r1
	bhi _081FE57E
	b _081FEA6E
_081FE57E:
	b _081FEA5E
	.align 2, 0
_081FE580: .4byte 0x000007F2
_081FE584:
	mov r2, sl
	ldr r0, [r2, #4]
	movs r3, #0xcc
	adds r3, r3, r7
	mov sb, r3
	cmp r0, #0
	bne _081FE61E
	ldr r1, _081FE5D4 @ =0x00000807
	add r1, r8
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081FE5D8 @ =0x00000806
	add r0, r8
	ldrb r1, [r0]
	mov r0, sb
	movs r2, #1
	bl FUN_08234f90
	mov r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE5CE
	cmp r1, #0
	blt _081FE5CE
	ldr r0, _081FE5DC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE5CE
	ldr r0, _081FE5E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE5E4
_081FE5CE:
	movs r4, #0
	b _081FE5F2
	.align 2, 0
_081FE5D4: .4byte 0x00000807
_081FE5D8: .4byte 0x00000806
_081FE5DC: .4byte 0x030046A8
_081FE5E0: .4byte 0x030046AC
_081FE5E4:
	ldr r0, _081FE604 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE5F2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FE608
	adds r0, #4
	b _081FE614
	.align 2, 0
_081FE604: .4byte 0x030046A4
_081FE608:
	ldr r0, _081FE670 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE614:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
_081FE61E:
	add r4, sp, #0x14
	adds r5, r7, #0
	adds r5, #0x50
	mov r1, sb
	ldrh r0, [r1]
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r3, sb
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	strh r2, [r4, #2]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp, #0x24]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _081FE674
	movs r1, #1
	rsbs r1, r1, #0
	b _081FE6A6
	.align 2, 0
_081FE670: .4byte 0x030046A4
_081FE674:
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #0x50
	muls r0, r2, r0
	adds r1, r6, #0
	bl Div
	strh r0, [r4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	movs r1, #0x50
	muls r0, r1, r0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	movs r3, #0x50
	muls r0, r3, r0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #4]
	ldr r1, [sp, #0x24]
_081FE6A6:
	movs r0, #0xc8
	lsls r0, r0, #5
	cmp r1, r0
	bgt _081FE6DC
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x50]
	str r1, [r7, #0x54]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r3, [sp, #0x2c]
	ldr r0, [r3]
	orrs r0, r1
	str r0, [r3]
	ldr r0, _081FE6D8 @ =0x0000022B
	bl PlaySound_082406e0
	bl FUN_081fafd4
	mov r0, sl
	bl FUN_081fa5b0
	b _081FE6F6
	.align 2, 0
_081FE6D8: .4byte 0x0000022B
_081FE6DC:
	add r0, sp, #0x14
	ldrh r0, [r0]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
_081FE6F6:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE71A
	cmp r1, #0
	blt _081FE71A
	ldr r0, _081FE720 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE71A
	ldr r0, _081FE724 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE728
_081FE71A:
	movs r4, #0
	b _081FE736
	.align 2, 0
_081FE720: .4byte 0x030046A8
_081FE724: .4byte 0x030046AC
_081FE728:
	ldr r0, _081FE748 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE736:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FE74C
	adds r0, #4
	b _081FE758
	.align 2, 0
_081FE748: .4byte 0x030046A4
_081FE74C:
	ldr r0, _081FE790 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE758:
	ldrb r1, [r0]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	mov r5, sl
	ldr r0, [r5, #4]
	ands r0, r2
	cmp r0, #0
	bne _081FE7A8
	ldr r2, _081FE794 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FE798 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FE79C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FE7A0
	adds r0, r7, #0
	movs r1, #0xfa
	bl FUN_081fad7c
	b _081FE7A8
	.align 2, 0
_081FE790: .4byte 0x030046A4
_081FE794: .4byte 0x030046B8
_081FE798: .4byte 0x000003FF
_081FE79C: .4byte 0x0203B400
_081FE7A0:
	adds r0, r7, #0
	movs r1, #0xfa
	bl FUN_081fabc0
_081FE7A8:
	mov r2, sl
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl FUN_08022dfc
	b _081FEA6E
_081FE7C4:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0x96
	bl FUN_08022c24
	mov r3, sl
	ldr r0, [r3, #4]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _081FE7DE
	bl FUN_081fafd4
_081FE7DE:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl FUN_08022dfc
	mov r5, sl
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	cmp r0, #0xa
	bhi _081FE7FE
	b _081FEA6E
_081FE7FE:
	b _081FEA5E
_081FE800:
	mov r0, sl
	ldr r1, [r0, #4]
	movs r2, #0xcc
	adds r2, r2, r7
	mov sb, r2
	cmp r1, #0
	bne _081FE896
	ldr r0, _081FE84C @ =0x00000807
	add r0, r8
	strb r1, [r0]
	ldr r0, _081FE850 @ =0x00000806
	add r0, r8
	ldrb r1, [r0]
	mov r0, sb
	movs r2, #0
	bl FUN_08234f90
	mov r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE848
	cmp r1, #0
	blt _081FE848
	ldr r0, _081FE854 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE848
	ldr r0, _081FE858 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE85C
_081FE848:
	movs r4, #0
	b _081FE86A
	.align 2, 0
_081FE84C: .4byte 0x00000807
_081FE850: .4byte 0x00000806
_081FE854: .4byte 0x030046A8
_081FE858: .4byte 0x030046AC
_081FE85C:
	ldr r0, _081FE87C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE86A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FE880
	adds r0, #4
	b _081FE88C
	.align 2, 0
_081FE87C: .4byte 0x030046A4
_081FE880:
	ldr r0, _081FE8F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE88C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
_081FE896:
	mov r3, sl
	ldr r0, [r3, #4]
	adds r0, #1
	str r0, [r3, #4]
	add r4, sp, #0x1c
	adds r5, r7, #0
	adds r5, #0x50
	mov r1, sb
	ldrh r0, [r1]
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r4]
	mov r3, sb
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	strh r2, [r4, #2]
	movs r0, #0x50
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp, #0x28]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	cmp r6, #0
	bne _081FE8F8
	movs r1, #1
	rsbs r1, r1, #0
	b _081FE930
	.align 2, 0
_081FE8F4: .4byte 0x030046A4
_081FE8F8:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #4]
	ldr r1, [sp, #0x28]
_081FE930:
	movs r0, #0xc8
	lsls r0, r0, #5
	cmp r1, r0
	ble _081FE940
	mov r1, sl
	ldr r0, [r1, #4]
	cmp r0, #0xa
	bls _081FE952
_081FE940:
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x50]
	str r1, [r7, #0x54]
	mov r0, sl
	bl FUN_081fa5b0
	b _081FE96C
_081FE952:
	add r0, sp, #0x1c
	ldrh r0, [r0]
	ldrh r3, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r4, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
_081FE96C:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FE990
	cmp r1, #0
	blt _081FE990
	ldr r0, _081FE994 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FE990
	ldr r0, _081FE998 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FE99C
_081FE990:
	movs r4, #0
	b _081FE9AA
	.align 2, 0
_081FE994: .4byte 0x030046A8
_081FE998: .4byte 0x030046AC
_081FE99C:
	ldr r0, _081FE9BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FE9AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081FE9C0
	adds r0, #4
	b _081FE9CC
	.align 2, 0
_081FE9BC: .4byte 0x030046A4
_081FE9C0:
	ldr r0, _081FE9D8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FE9CC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	b _081FEA6E
	.align 2, 0
_081FE9D8: .4byte 0x030046A4
_081FE9DC:
	mov r3, sl
	ldr r0, [r3, #4]
	cmp r0, #0
	bne _081FEA42
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #4
	bl FUN_08022c9c
	mov r5, sl
	str r4, [r5, #4]
	ldr r0, _081FEA14 @ =0x000007CC
	add r0, r8
	ldr r0, [r0]
	bl FUN_08203d38
	b _081FEA42
	.align 2, 0
_081FEA14: .4byte 0x000007CC
_081FEA18:
	mov r1, sl
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FEA42
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	movs r0, #2
	str r0, [sp]
	movs r4, #1
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #2
	bl FUN_08022c9c
	mov r2, sl
	str r4, [r2, #4]
_081FEA42:
	movs r1, #0x8f
	lsls r1, r1, #2
	add r1, r8
	movs r2, #0x87
	lsls r2, r2, #2
	add r2, r8
	adds r0, r7, #0
	bl FUN_08022dfc
_081FEA54:
	adds r0, r7, #0
	adds r0, #0xaa
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FEA6E
_081FEA5E:
	mov r0, sl
	bl FUN_081fa5b0
	b _081FEA6E
_081FEA66:
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FEA6E:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081fea80
FUN_081fea80: @ 0x081FEA80
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sb, r1
	mov sl, r7
	adds r1, r7, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FEB10
	movs r2, #0
	strb r2, [r1]
	movs r0, #0x8f
	lsls r0, r0, #2
	adds r1, r7, r0
	subs r0, #0x20
	adds r6, r7, r0
	movs r0, #2
	str r0, [sp]
	movs r0, #1
	mov r8, r0
	str r0, [sp, #4]
	str r2, [sp, #8]
	adds r0, r7, #0
	adds r2, r6, #0
	movs r3, #0xa
	bl FUN_08022c9c
	ldr r1, _081FEB6C @ =0x00000844
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r7, #0
	bl FUN_08023090
	movs r0, #0x97
	lsls r0, r0, #2
	adds r5, r7, r0
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08022fb8
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0xf
	movs r3, #0
	bl FUN_082370cc
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r7, r0
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r4, #8]
	mov r1, r8
	orrs r0, r1
	str r0, [r4, #8]
	ldr r1, _081FEB70 @ =0x000007CC
	adds r0, r7, r1
	ldr r0, [r0]
	bl FUN_08203d38
_081FEB10:
	ldr r0, _081FEB74 @ =0x00000804
	adds r1, r7, r0
	movs r3, #0
	movs r2, #0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r7, r1
	strh r2, [r0]
	subs r1, #0x38
	adds r0, r7, r1
	strb r3, [r0]
	movs r2, #9
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r4, r7, r0
	subs r0, #0x80
	adds r1, r7, r0
	adds r0, r4, #0
	bl FUN_082372cc
	mov r1, sb
	cmp r1, #0xd9
	bgt _081FEB8E
	ldr r1, _081FEB78 @ =0x00000155
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FEB84
	adds r0, r7, #0
	adds r0, #0xe0
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #1
	bhi _081FEB7C
	ldr r0, [r4, #8]
	subs r1, #5
	ands r0, r1
	b _081FEB82
	.align 2, 0
_081FEB6C: .4byte 0x00000844
_081FEB70: .4byte 0x000007CC
_081FEB74: .4byte 0x00000804
_081FEB78: .4byte 0x00000155
_081FEB7C:
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
_081FEB82:
	str r0, [r4, #8]
_081FEB84:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_081fa628
	b _081FEB96
_081FEB8E:
	ldr r0, [r4, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #8]
_081FEB96:
	mov r0, sb
	cmp r0, #0x80
	bne _081FEBA8
	movs r1, #0x97
	lsls r1, r1, #2
	add r1, sl
	adds r0, r7, #0
	bl FUN_08023024
_081FEBA8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081febb8
FUN_081febb8: @ 0x081FEBB8
	adds r3, r0, #0
	movs r2, #0x1c
	adds r1, r3, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r1, r3, r0
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081febe4
FUN_081febe4: @ 0x081FEBE4
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FEC2E
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #4
	str r2, [sp]
	movs r2, #0xe
	movs r3, #0
	bl FUN_082370cc
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_081fa590
_081FEC2E:
	movs r2, #0x1c
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r2, r4, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fec60
FUN_081fec60: @ 0x081FEC60
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FECB4
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0xe
	movs r3, #0
	bl FUN_082370cc
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r5, r0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r5, r2
	bl FUN_081fa590
	ldr r0, [r4, #8]
	movs r1, #2
	orrs r0, r1
	str r0, [r4, #8]
_081FECB4:
	ldr r0, _081FED04 @ =0x000002D1
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _081FECC8
	movs r0, #0x7f
	strb r0, [r1]
_081FECC8:
	ldrb r1, [r1]
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	movs r2, #0x1c
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081FED04: .4byte 0x000002D1

	thumb_func_start FUN_081fed08
FUN_081fed08: @ 0x081FED08
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r7, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FED50
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #4
	str r2, [sp]
	movs r2, #0x10
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_081fa590
_081FED50:
	movs r0, #0xf
	ands r0, r4
	cmp r0, #0
	bne _081FED90
	ldr r2, _081FED7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FED80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FED84 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FED88
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FED90
	.align 2, 0
_081FED7C: .4byte 0x030046B8
_081FED80: .4byte 0x000003FF
_081FED84: .4byte 0x0203B400
_081FED88:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FED90:
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #8]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r6, r5, r1
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_082372cc
	cmp r0, #0
	beq _081FEDCA
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0x11
	movs r3, #1
	bl FUN_082370cc
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FEDCA:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fedec
FUN_081fedec: @ 0x081FEDEC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _081FEE30 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FEE9A
	movs r2, #0xc7
	lsls r2, r2, #2
	adds r6, r5, r2
	adds r0, r6, #0
	movs r1, #0x1d
	bl Sprite_SetPlttID
	movs r0, #0xf
	ands r0, r4
	cmp r0, #0
	bne _081FEE88
	asrs r1, r4, #4
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _081FEE4E
	cmp r1, #1
	bgt _081FEE34
	cmp r1, #0
	beq _081FEE3E
	b _081FEE88
	.align 2, 0
_081FEE30: .4byte 0x03002BE0
_081FEE34:
	cmp r1, #2
	beq _081FEE5E
	cmp r1, #3
	beq _081FEE74
	b _081FEE88
_081FEE3E:
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0x30
	b _081FEE6C
_081FEE4E:
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0x31
	b _081FEE6C
_081FEE5E:
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0x32
_081FEE6C:
	movs r3, #1
	bl FUN_082370cc
	b _081FEE88
_081FEE74:
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0x33
	movs r3, #1
	bl FUN_082370cc
_081FEE88:
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r5, r2
	bl FUN_082372cc
	b _081FEF28
_081FEE9A:
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r6, r5, r0
	adds r0, r6, #0
	movs r1, #0x26
	bl Sprite_SetPlttID
	movs r0, #0xf
	ands r0, r4
	cmp r0, #0
	bne _081FEF18
	asrs r1, r4, #4
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _081FEEDE
	cmp r1, #1
	bgt _081FEEC4
	cmp r1, #0
	beq _081FEECE
	b _081FEF18
_081FEEC4:
	cmp r1, #2
	beq _081FEEEE
	cmp r1, #3
	beq _081FEF04
	b _081FEF18
_081FEECE:
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0xf7
	b _081FEEFC
_081FEEDE:
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0xf8
	b _081FEEFC
_081FEEEE:
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0xf9
_081FEEFC:
	movs r3, #1
	bl FUN_082370cc
	b _081FEF18
_081FEF04:
	movs r0, #0xbf
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #0xfa
	movs r3, #1
	bl FUN_082370cc
_081FEF18:
	movs r1, #0xc7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0xbf
	lsls r2, r2, #2
	adds r1, r5, r2
	bl FUN_082372cc
_081FEF28:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081fef30
FUN_081fef30: @ 0x081FEF30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	adds r5, r6, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FEF8A
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #4
	str r2, [sp]
	movs r2, #0x12
	movs r3, #2
	bl FUN_082370cc
	movs r7, #0xaf
	lsls r7, r7, #2
	adds r2, r5, r7
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_081fa590
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	ldr r7, _081FEFB8 @ =0x000003C6
	adds r0, r5, r7
	strh r4, [r0]
_081FEF8A:
	movs r0, #0xf
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _081FEFD0
	ldr r2, _081FEFBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FEFC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FEFC4 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FEFC8
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FEFD0
	.align 2, 0
_081FEFB8: .4byte 0x000003C6
_081FEFBC: .4byte 0x030046B8
_081FEFC0: .4byte 0x000003FF
_081FEFC4: .4byte 0x0203B400
_081FEFC8:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FEFD0:
	movs r7, #0xa7
	lsls r7, r7, #2
	adds r0, r5, r7
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	bl FUN_082372cc
	cmp r0, #0
	beq _081FF010
	adds r0, r6, #0
	adds r0, #0xa7
	movs r3, #0
	movs r2, #1
	strb r2, [r0]
	ldr r1, _081FF084 @ =FUN_081ff148
	movs r0, #0x10
	adds r4, r6, #0
	adds r4, #0xa3
	strb r0, [r4]
	adds r0, r6, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	strb r2, [r0]
_081FF010:
	movs r2, #0x10
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r7, r8
	cmp r7, #0xd
	bgt _081FF024
	b _081FF132
_081FF024:
	ldr r0, _081FF088 @ =0x085AE708
	mov ip, r0
	ldr r1, _081FF08C @ =0x000003C6
	adds r3, r5, r1
	ldrh r0, [r3]
	lsls r0, r0, #3
	add ip, r0
	movs r7, #0xf1
	lsls r7, r7, #2
	adds r2, r5, r7
	ldrh r0, [r2]
	adds r0, #1
	movs r4, #0
	strh r0, [r2]
	ldrh r1, [r2]
	mov r7, ip
	ldr r0, [r7]
	cmp r1, r0
	blo _081FF05C
	strh r4, [r2]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc
	bls _081FF05C
	strh r4, [r3]
_081FF05C:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r7, r5, r0
	adds r2, r6, #0
	adds r2, #0x50
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF090
	asrs r0, r0, #8
	b _081FF096
	.align 2, 0
_081FF084: .4byte FUN_081ff148
_081FF088: .4byte 0x085AE708
_081FF08C: .4byte 0x000003C6
_081FF090:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF096:
	strh r0, [r7]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF0A8
	asrs r0, r0, #8
	b _081FF0AE
_081FF0A8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF0AE:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081FF0C2
	asrs r0, r0, #8
	b _081FF0C8
_081FF0C2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF0C8:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _081FF140 @ =0x030047C8
	ldrh r0, [r7]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r7]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r7, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r7, #4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r3, r5, r1
	mov r2, ip
	ldrh r0, [r2, #4]
	ldrh r7, [r3]
	adds r0, r0, r7
	strh r0, [r3]
	ldr r0, _081FF144 @ =0x0000033E
	adds r1, r5, r0
	ldrh r0, [r2, #6]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r7, #0xed
	lsls r7, r7, #2
	adds r2, r5, r7
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	mov r1, r8
	bl FUN_081fedec
	movs r0, #0xc7
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #8]
	subs r7, #0x1c
	adds r1, r5, r7
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_081FF132:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FF140: .4byte 0x030047C8
_081FF144: .4byte 0x0000033E

	thumb_func_start FUN_081ff148
FUN_081ff148: @ 0x081FF148
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	mov r8, r1
	adds r5, r7, #0
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FF1A4
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #4
	str r2, [sp]
	movs r2, #0x11
	movs r3, #1
	bl FUN_082370cc
	movs r6, #0xaf
	lsls r6, r6, #2
	adds r2, r5, r6
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_081fa590
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
	ldr r6, _081FF1EC @ =0x000003C6
	adds r0, r5, r6
	strh r4, [r0]
_081FF1A4:
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	bl FUN_082372cc
	adds r4, r0, #0
	movs r0, #0xf
	mov r6, r8
	ands r0, r6
	cmp r0, #0
	bne _081FF204
	ldr r2, _081FF1F0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FF1F4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FF1F8 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FF1FC
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FF204
	.align 2, 0
_081FF1EC: .4byte 0x000003C6
_081FF1F0: .4byte 0x030046B8
_081FF1F4: .4byte 0x000003FF
_081FF1F8: .4byte 0x0203B400
_081FF1FC:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FF204:
	cmp r4, #0
	beq _081FF220
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r1, #0
	strh r1, [r0]
	ldr r6, _081FF28C @ =0x000003C6
	adds r0, r5, r6
	strh r1, [r0]
	adds r1, r7, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
_081FF220:
	movs r2, #0x10
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081FF290 @ =0x085AE688
	mov ip, r0
	ldr r1, _081FF28C @ =0x000003C6
	adds r3, r5, r1
	ldrh r0, [r3]
	lsls r0, r0, #3
	add ip, r0
	movs r6, #0xf1
	lsls r6, r6, #2
	adds r2, r5, r6
	ldrh r0, [r2]
	adds r0, #1
	movs r4, #0
	strh r0, [r2]
	ldrh r1, [r2]
	mov r6, ip
	ldr r0, [r6]
	cmp r1, r0
	blo _081FF264
	strh r4, [r2]
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _081FF264
	strh r4, [r3]
_081FF264:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r6, r5, r0
	adds r2, r7, #0
	adds r2, #0x50
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF294
	asrs r0, r0, #8
	b _081FF29A
	.align 2, 0
_081FF28C: .4byte 0x000003C6
_081FF290: .4byte 0x085AE688
_081FF294:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF29A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF2AC
	asrs r0, r0, #8
	b _081FF2B2
_081FF2AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF2B2:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081FF2C6
	asrs r0, r0, #8
	b _081FF2CC
_081FF2C6:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF2CC:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _081FF344 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r3, r5, r1
	mov r2, ip
	ldrh r0, [r2, #4]
	ldrh r6, [r3]
	adds r0, r0, r6
	strh r0, [r3]
	ldr r0, _081FF348 @ =0x0000033E
	adds r1, r5, r0
	ldrh r0, [r2, #6]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r6, #0xc7
	lsls r6, r6, #2
	adds r1, r5, r6
	ldr r0, [r1, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1, #8]
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r1, #0xed
	lsls r1, r1, #2
	adds r2, r5, r1
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r5, #0
	mov r1, r8
	bl FUN_081fedec
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FF344: .4byte 0x030047C8
_081FF348: .4byte 0x0000033E

	thumb_func_start FUN_081ff34c
FUN_081ff34c: @ 0x081FF34C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r5, r0, #0
	mov sb, r1
	mov r8, r5
	adds r1, r5, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FF3AC
	movs r4, #0
	strb r4, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #6
	str r2, [sp]
	movs r2, #0x10
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r5, r0
	ldr r0, [r5, #0x50]
	ldr r1, [r5, #0x54]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_081fa590
	movs r2, #0xf1
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r4, [r0]
	ldr r4, _081FF42C @ =0x000003C6
	adds r1, r5, r4
	movs r0, #4
	strh r0, [r1]
_081FF3AC:
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0, #8]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r5, r2
	bl FUN_082372cc
	mov sl, r0
	movs r2, #0x10
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r4, _081FF430 @ =0x085AE660
	mov ip, r4
	ldr r0, _081FF42C @ =0x000003C6
	adds r3, r5, r0
	ldrh r0, [r3]
	lsls r0, r0, #3
	add ip, r0
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r2, r5, r1
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldrh r1, [r2]
	mov r4, ip
	ldr r0, [r4]
	cmp r1, r0
	bls _081FF406
	movs r0, #0
	strh r0, [r2]
	ldrh r0, [r3]
	cmp r0, #0
	beq _081FF406
	subs r0, #1
	strh r0, [r3]
_081FF406:
	movs r6, #0xcf
	lsls r6, r6, #2
	add r6, r8
	adds r2, r5, #0
	adds r2, #0x50
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF434
	asrs r0, r0, #8
	b _081FF43A
	.align 2, 0
_081FF42C: .4byte 0x000003C6
_081FF430: .4byte 0x085AE660
_081FF434:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF43A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _081FF44C
	asrs r0, r0, #8
	b _081FF452
_081FF44C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF452:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _081FF466
	asrs r0, r0, #8
	b _081FF46C
_081FF466:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_081FF46C:
	subs r2, r4, r0
	movs r7, #0
	adds r4, r4, r0
	ldr r3, _081FF560 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r3, #0xcf
	lsls r3, r3, #2
	add r3, r8
	mov r1, ip
	ldrh r0, [r1, #4]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldr r1, _081FF564 @ =0x0000033E
	add r1, r8
	mov r4, ip
	ldrh r0, [r4, #6]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r2, #0xed
	lsls r2, r2, #2
	add r2, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r6, #0xc7
	lsls r6, r6, #2
	add r6, r8
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	movs r4, #0xe6
	lsls r4, r4, #2
	add r4, r8
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	mov r0, r8
	mov r1, sb
	bl FUN_081fedec
	mov r0, sl
	cmp r0, #0
	beq _081FF57C
	adds r0, r5, #0
	adds r0, #0xa7
	movs r2, #1
	strb r2, [r0]
	movs r1, #0xa7
	lsls r1, r1, #2
	add r1, r8
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
	ldr r0, [r6, #8]
	orrs r0, r2
	str r0, [r6, #8]
	ldr r0, [r4]
	orrs r0, r2
	str r0, [r4]
	ldr r1, _081FF568 @ =FUN_081febb8
	movs r0, #0xb
	adds r3, r5, #0
	adds r3, #0xa3
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r7, [r0]
	adds r0, #0x1d
	strb r2, [r0]
	add r4, sp, #0x3c
	str r7, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081FF56C @ =0x05000002
	bl CpuSet
	movs r0, #0xaf
	lsls r0, r0, #2
	add r0, r8
	ldr r2, _081FF570 @ =0x0000F422
	ldr r3, _081FF574 @ =0x0000121B
	movs r1, #6
	str r1, [sp]
	str r7, [sp, #4]
	movs r1, #9
	str r1, [sp, #8]
	ldr r1, _081FF578 @ =0x00000237
	str r1, [sp, #0xc]
	movs r1, #2
	str r1, [sp, #0x10]
	str r7, [sp, #0x14]
	str r7, [sp, #0x18]
	str r7, [sp, #0x1c]
	str r7, [sp, #0x20]
	str r7, [sp, #0x24]
	str r7, [sp, #0x28]
	str r7, [sp, #0x2c]
	str r7, [sp, #0x30]
	str r7, [sp, #0x34]
	adds r1, r4, #0
	bl FUN_081f22c0
	b _081FF5BC
	.align 2, 0
_081FF560: .4byte 0x030047C8
_081FF564: .4byte 0x0000033E
_081FF568: .4byte FUN_081febb8
_081FF56C: .4byte 0x05000002
_081FF570: .4byte 0x0000F422
_081FF574: .4byte 0x0000121B
_081FF578: .4byte 0x00000237
_081FF57C:
	movs r0, #0xf
	mov r1, sb
	ands r0, r1
	cmp r0, #0
	bne _081FF5BC
	ldr r2, _081FF5A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FF5AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081FF5B0 @ =0x0203B400
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x80
	ble _081FF5B4
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fad7c
	b _081FF5BC
	.align 2, 0
_081FF5A8: .4byte 0x030046B8
_081FF5AC: .4byte 0x000003FF
_081FF5B0: .4byte 0x0203B400
_081FF5B4:
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_081fabc0
_081FF5BC:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ff5cc
FUN_081ff5cc: @ 0x081FF5CC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, r1, #0
	adds r6, r4, #0
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _081FF626
	ldr r2, _081FF604 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r5, _081FF608 @ =0x000003FF
	ands r1, r5
	str r1, [r2]
	lsls r0, r1, #1
	ldr r3, _081FF60C @ =0x0203B400
	adds r0, r0, r3
	movs r3, #0xff
	ldrb r0, [r0]
	cmp r0, #0xef
	bgt _081FF610
	adds r0, r4, #0
	adds r0, #0x50
	bl FUN_081fae7c
	b _081FF626
	.align 2, 0
_081FF604: .4byte 0x030046B8
_081FF608: .4byte 0x000003FF
_081FF60C: .4byte 0x0203B400
_081FF610:
	adds r0, r1, #1
	ands r0, r5
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081FF654 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	ands r1, r3
	adds r0, r4, #0
	bl FUN_081fad7c
_081FF626:
	movs r3, #0xa7
	lsls r3, r3, #2
	adds r1, r6, r3
	ldr r0, [r1, #8]
	movs r2, #1
	orrs r0, r2
	str r0, [r1, #8]
	movs r0, #0xe6
	lsls r0, r0, #2
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x10
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081FF654: .4byte 0x0203B400

	thumb_func_start FUN_081ff658
FUN_081ff658: @ 0x081FF658
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r4, #0
	adds r1, r4, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FF6FC
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa7
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0x87
	lsls r2, r2, #2
	adds r1, r4, r2
	movs r2, #4
	str r2, [sp]
	movs r2, #0xe
	movs r3, #0
	bl FUN_082370cc
	movs r0, #0xaf
	lsls r0, r0, #2
	adds r2, r4, r0
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #3
	ldr r3, _081FF6C0 @ =0x00000239
	movs r2, #0xf9
	lsls r2, r2, #3
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _081FF6C4 @ =0x000007CA
	adds r5, r4, r0
	movs r2, #0
	strh r3, [r5]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	beq _081FF6E4
	cmp r0, #2
	bgt _081FF6C8
	cmp r0, #1
	beq _081FF6CE
	b _081FF6F4
	.align 2, 0
_081FF6C0: .4byte 0x00000239
_081FF6C4: .4byte 0x000007CA
_081FF6C8:
	cmp r0, #3
	beq _081FF6E4
	b _081FF6F4
_081FF6CE:
	ldr r1, _081FF6E0 @ =0x000007C9
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_081fa620
	strh r0, [r5]
	b _081FF6FC
	.align 2, 0
_081FF6E0: .4byte 0x000007C9
_081FF6E4:
	ldr r1, _081FF6F0 @ =0x000007C9
	adds r0, r4, r1
	strb r2, [r0]
	strh r3, [r5]
	b _081FF6FC
	.align 2, 0
_081FF6F0: .4byte 0x000007C9
_081FF6F4:
	ldr r2, _081FF730 @ =0x000007C9
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
_081FF6FC:
	movs r0, #0xa7
	lsls r0, r0, #2
	adds r2, r6, r0
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	movs r1, #0xe6
	lsls r1, r1, #2
	adds r2, r6, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #0x10
	adds r1, r4, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081FF730: .4byte 0x000007C9

	thumb_func_start FUN_081ff734
FUN_081ff734: @ 0x081FF734
	push {lr}
	bl FUN_08022f78
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ff740
FUN_081ff740: @ 0x081FF740
	push {lr}
	mov ip, r0
	mov r2, ip
	adds r2, #0xa2
	ldrb r0, [r2]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bhi _081FF77C
	ldr r1, _081FF778 @ =0x085AE768
	ldrb r2, [r2]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	mov r0, ip
	adds r0, #0xa3
	movs r3, #0
	strb r2, [r0]
	adds r0, #0x55
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	mov r1, ip
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	b _081FF77E
	.align 2, 0
_081FF778: .4byte 0x085AE768
_081FF77C:
	movs r0, #0
_081FF77E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ff784
FUN_081ff784: @ 0x081FF784
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	adds r7, r4, #0
	movs r1, #0x10
	adds r0, r4, #0
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081FF7D6
	ldr r1, _081FF7DC @ =0x00000802
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081FF7C4
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08236524
	ldrh r1, [r6, #0x3e]
	ldr r2, _081FF7E0 @ =0x000007D2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [r5, #0x34]
	adds r0, r4, #0
	adds r0, #0xb4
	str r1, [r0]
	ldr r1, [r5, #0x38]
	adds r0, #4
	str r1, [r0]
_081FF7C4:
	movs r1, #4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081FF7D6
	ldr r0, _081FF7E4 @ =0x000007DE
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_081FF7D6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FF7DC: .4byte 0x00000802
_081FF7E0: .4byte 0x000007D2
_081FF7E4: .4byte 0x000007DE

	thumb_func_start FUN_081ff7e8
FUN_081ff7e8: @ 0x081FF7E8
	movs r0, #0
	strh r0, [r1, #0x3e]
	ldr r0, _081FF7F8 @ =0x000007D4
	adds r2, r2, r0
	movs r0, #1
	str r0, [r2]
	bx lr
	.align 2, 0
_081FF7F8: .4byte 0x000007D4

	thumb_func_start FUN_081ff7fc
FUN_081ff7fc: @ 0x081FF7FC
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r2, _081FF894 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	orrs r0, r3
	ldr r1, _081FF898 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _081FF89C @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x97
	lsls r0, r0, #2
	adds r1, r4, r0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081FF8A0 @ =FUN_081ff7e8
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, _081FF8A4 @ =0x000007E2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r3, _081FF8A8 @ =0x000007E4
	adds r0, r4, r3
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	ldr r0, _081FF8AC @ =0x000007E6
	adds r4, r4, r0
	movs r3, #0
	ldrsh r0, [r4, r3]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_082364f8
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081FF894: .4byte 0xFFFF0000
_081FF898: .4byte 0x0000FFFF
_081FF89C: .4byte 0x00002001
_081FF8A0: .4byte FUN_081ff7e8
_081FF8A4: .4byte 0x000007E2
_081FF8A8: .4byte 0x000007E4
_081FF8AC: .4byte 0x000007E6

	thumb_func_start FUN_081ff8b0
FUN_081ff8b0: @ 0x081FF8B0
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #0xae
	lsls r0, r0, #1
	adds r4, r5, r0
	ldr r2, _081FF934 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	lsls r3, r3, #1
	orrs r0, r3
	ldr r1, _081FF938 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _081FF93C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x97
	lsls r0, r0, #2
	adds r1, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081FF940 @ =FUN_081ff784
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	ldr r2, _081FF944 @ =0x00000808
	adds r0, r4, #0
	adds r1, r6, #0
	movs r3, #4
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081FF934: .4byte 0xFFFF0000
_081FF938: .4byte 0x0000FFFF
_081FF93C: .4byte 0x00005001
_081FF940: .4byte FUN_081ff784
_081FF944: .4byte 0x00000808

	thumb_func_start FUN_081ff948
FUN_081ff948: @ 0x081FF948
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r0, _081FF96C @ =0x000007DC
	adds r4, r3, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _081FF982
	adds r2, r3, #0
	adds r2, #0x90
	movs r5, #0
	ldrsh r1, [r2, r5]
	subs r1, r1, r0
	cmp r1, #1
	ble _081FF970
	strh r1, [r2]
	b _081FF982
	.align 2, 0
_081FF96C: .4byte 0x000007DC
_081FF970:
	movs r0, #1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xc
	adds r1, r3, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081FF982:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ff988
FUN_081ff988: @ 0x081FF988
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r1, _081FFAEC @ =0x000007D2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r5, #0
	strh r5, [r0]
	cmp r2, #0
	bgt _081FF9A8
	b _081FFB6C
_081FF9A8:
	ldr r0, _081FFAF0 @ =0x000007FC
	adds r0, r7, r0
	str r0, [sp, #0x20]
	adds r1, #0x2c
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r1, r1, r2
	ldr r3, [sp, #0x20]
	ldrh r0, [r3]
	subs r0, r0, r1
	strh r0, [r3]
	movs r5, #0x90
	adds r5, r5, r7
	mov sl, r5
	ldrh r0, [r5]
	subs r0, r0, r2
	strh r0, [r5]
	ldr r1, _081FFAF4 @ =0x00000802
	adds r0, r7, r1
	movs r3, #0xf
	strh r3, [r0]
	movs r5, #0x80
	lsls r5, r5, #4
	adds r1, r7, r5
	movs r0, #0xa
	strh r0, [r1]
	movs r0, #0xa1
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r3, #0xf2
	lsls r3, r3, #2
	adds r0, r7, r3
	str r0, [r1]
	ldr r4, _081FFAF8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r1, #0x10
	orrs r0, r1
	ldr r5, _081FFAFC @ =0x0000FFFF
	ands r0, r5
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x14]
	movs r1, #0xae
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r3, r7, #0
	adds r3, #0x50
	add r1, sp, #0x10
	str r1, [sp]
	movs r1, #1
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldr r2, _081FFB00 @ =0x000007DE
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _081FFA92
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r3, #0xa4
	orrs r0, r3
	ands r0, r5
	movs r1, #0x80
	lsls r1, r1, #0xd
	orrs r0, r1
	str r0, [sp, #0x18]
	add r2, sp, #0x18
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	ldr r6, _081FFB04 @ =0x0203B400
	ldr r3, _081FFB08 @ =0x030046B8
	mov sb, r3
	ldr r0, [r3]
	adds r0, #1
	ldr r5, _081FFB0C @ =0x000003FF
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrb r3, [r1]
	adds r0, #1
	ands r0, r5
	lsls r1, r0, #1
	adds r1, r1, r6
	ldrh r4, [r1]
	movs r1, #3
	mov r8, r1
	ands r4, r1
	adds r4, #2
	adds r0, #1
	ands r0, r5
	mov r5, sb
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r1, [r0]
	mov r0, r8
	ands r1, r0
	adds r1, #0x14
	movs r5, #0x97
	lsls r5, r5, #2
	adds r0, r7, r5
	str r4, [sp]
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #3
	bl FUN_080ddcc8
_081FFA92:
	mov r1, sl
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bgt _081FFB14
	movs r0, #0xe1
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r5, #0
	mov r3, sl
	strh r5, [r3]
	movs r2, #2
	adds r1, r7, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #6
	adds r0, r7, #0
	adds r0, #0xa4
	movs r2, #0
	strb r2, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	movs r3, #0
	str r3, [r0]
	subs r0, #0x14
	movs r5, #1
	strb r5, [r0]
	ldr r1, _081FFB10 @ =FUN_081fea80
	adds r2, r7, #0
	adds r2, #0xa3
	movs r0, #0xa
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
	adds r0, #0x1d
	b _081FFB58
	.align 2, 0
_081FFAEC: .4byte 0x000007D2
_081FFAF0: .4byte 0x000007FC
_081FFAF4: .4byte 0x00000802
_081FFAF8: .4byte 0xFFFF0000
_081FFAFC: .4byte 0x0000FFFF
_081FFB00: .4byte 0x000007DE
_081FFB04: .4byte 0x0203B400
_081FFB08: .4byte 0x030046B8
_081FFB0C: .4byte 0x000003FF
_081FFB10: .4byte FUN_081fea80
_081FFB14:
	ldr r1, _081FFB60 @ =0x00000804
	adds r0, r7, r1
	movs r2, #0xf
	strh r2, [r0]
	ldr r0, _081FFB64 @ =0x000001C1
	bl PlaySound_082406e0
	ldr r3, [sp, #0x20]
	movs r5, #0
	ldrsh r0, [r3, r5]
	cmp r0, #0
	bgt _081FFB6C
	adds r0, r7, #0
	adds r0, #0x98
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	adds r2, r7, #0
	adds r2, #0xa3
	ldrb r0, [r2]
	cmp r0, #9
	bne _081FFB5A
	ldr r1, _081FFB68 @ =FUN_081fd000
	movs r0, #5
	strb r0, [r2]
	adds r0, r7, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	movs r3, #0
	str r3, [r0]
	adds r0, #0x1d
	movs r5, #1
_081FFB58:
	strb r5, [r0]
_081FFB5A:
	movs r0, #1
	b _081FFB6E
	.align 2, 0
_081FFB60: .4byte 0x00000804
_081FFB64: .4byte 0x000001C1
_081FFB68: .4byte FUN_081fd000
_081FFB6C:
	movs r0, #0
_081FFB6E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ffb80
FUN_081ffb80: @ 0x081FFB80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	mov r8, r4
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r7, r4, r0
	movs r6, #0
	ldr r0, _081FFBA0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r0, r4, r2
	b _081FFD82
	.align 2, 0
_081FFBA0: .4byte 0x03002B4C
_081FFBA4:
	ldr r0, _081FFBD4 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08022474
	ldrb r0, [r5, #6]
	cmp r0, #0x33
	bls _081FFBCA
	b _081FFD78
_081FFBCA:
	lsls r0, r0, #2
	ldr r1, _081FFBD8 @ =_081FFBDC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FFBD4: .4byte 0x03002B4C
_081FFBD8: .4byte _081FFBDC
_081FFBDC: @ jump table
	.4byte _081FFCAC @ case 0
	.4byte _081FFCC8 @ case 1
	.4byte _081FFD78 @ case 2
	.4byte _081FFD78 @ case 3
	.4byte _081FFD78 @ case 4
	.4byte _081FFD78 @ case 5
	.4byte _081FFD78 @ case 6
	.4byte _081FFD78 @ case 7
	.4byte _081FFD78 @ case 8
	.4byte _081FFD78 @ case 9
	.4byte _081FFD10 @ case 10
	.4byte _081FFD78 @ case 11
	.4byte _081FFD78 @ case 12
	.4byte _081FFD78 @ case 13
	.4byte _081FFD78 @ case 14
	.4byte _081FFD78 @ case 15
	.4byte _081FFD78 @ case 16
	.4byte _081FFD78 @ case 17
	.4byte _081FFD78 @ case 18
	.4byte _081FFD78 @ case 19
	.4byte _081FFD78 @ case 20
	.4byte _081FFD78 @ case 21
	.4byte _081FFD78 @ case 22
	.4byte _081FFD78 @ case 23
	.4byte _081FFD78 @ case 24
	.4byte _081FFD78 @ case 25
	.4byte _081FFD78 @ case 26
	.4byte _081FFD78 @ case 27
	.4byte _081FFD78 @ case 28
	.4byte _081FFD78 @ case 29
	.4byte _081FFD78 @ case 30
	.4byte _081FFD78 @ case 31
	.4byte _081FFD78 @ case 32
	.4byte _081FFD78 @ case 33
	.4byte _081FFD78 @ case 34
	.4byte _081FFD78 @ case 35
	.4byte _081FFD78 @ case 36
	.4byte _081FFD78 @ case 37
	.4byte _081FFD78 @ case 38
	.4byte _081FFD78 @ case 39
	.4byte _081FFD78 @ case 40
	.4byte _081FFD78 @ case 41
	.4byte _081FFD78 @ case 42
	.4byte _081FFD78 @ case 43
	.4byte _081FFD78 @ case 44
	.4byte _081FFD4C @ case 45
	.4byte _081FFD54 @ case 46
	.4byte _081FFD5C @ case 47
	.4byte _081FFD34 @ case 48
	.4byte _081FFD3C @ case 49
	.4byte _081FFD44 @ case 50
	.4byte _081FFD2C @ case 51
_081FFCAC:
	movs r2, #1
	movs r1, #0
	adds r0, r4, #0
	adds r0, #0xa4
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r2, [r0]
	b _081FFD78
_081FFCC8:
	ldrh r0, [r5, #8]
	adds r1, r4, #0
	adds r1, #0x50
	strh r0, [r1]
	ldrh r0, [r5, #0xa]
	adds r3, r4, #0
	adds r3, #0x52
	strh r0, [r3]
	ldrh r0, [r5, #0xc]
	adds r2, r4, #0
	adds r2, #0x54
	strh r0, [r2]
	ldrh r1, [r1]
	movs r0, #0x97
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r3]
	ldr r0, _081FFD0C @ =0x0000025E
	add r0, r8
	strh r1, [r0]
	ldrh r1, [r2]
	movs r0, #0x98
	lsls r0, r0, #2
	add r0, r8
	strh r1, [r0]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
	b _081FFD78
	.align 2, 0
_081FFD0C: .4byte 0x0000025E
_081FFD10:
	movs r1, #1
	movs r2, #0
	adds r0, r4, #0
	adds r0, #0xa4
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #0x16
	str r2, [r0]
	subs r0, #0x14
	strb r1, [r0]
	b _081FFD78
_081FFD2C:
	movs r3, #1
	movs r1, #0
	movs r2, #8
	b _081FFD62
_081FFD34:
	movs r3, #1
	movs r1, #0
	movs r2, #2
	b _081FFD62
_081FFD3C:
	movs r3, #1
	movs r1, #0
	movs r2, #6
	b _081FFD62
_081FFD44:
	movs r3, #1
	movs r1, #0
	movs r2, #7
	b _081FFD62
_081FFD4C:
	movs r3, #1
	movs r1, #0
	movs r2, #3
	b _081FFD62
_081FFD54:
	movs r3, #1
	movs r1, #0
	movs r2, #4
	b _081FFD62
_081FFD5C:
	movs r3, #1
	movs r1, #0
	movs r2, #5
_081FFD62:
	adds r0, r4, #0
	adds r0, #0xa4
	strb r3, [r0]
	adds r0, #1
	strb r1, [r0]
	adds r0, #1
	strb r2, [r0]
	adds r0, #0x16
	str r1, [r0]
	subs r0, #0x14
	strb r3, [r0]
_081FFD78:
	adds r6, #1
	ldr r0, _081FFD98 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_081FFD82:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _081FFD8E
	b _081FFBA4
_081FFD8E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081FFD98: .4byte 0x03002B4C

	thumb_func_start FUN_081ffd9c
FUN_081ffd9c: @ 0x081FFD9C
	push {lr}
	adds r2, r0, #0
	adds r2, #0xa2
	movs r1, #0
	strb r1, [r2]
	bl FUN_081ffb80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081ffdb0
FUN_081ffdb0: @ 0x081FFDB0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov sb, r0
	mov r7, sb
	movs r3, #0x97
	lsls r3, r3, #2
	add r3, sb
	mov r2, sb
	ldr r0, [r2, #0x50]
	ldr r1, [r2, #0x54]
	str r0, [r3]
	str r1, [r3, #4]
	ldr r1, _081FFE80 @ =0x00000804
	add r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	beq _081FFE32
	subs r0, #1
	strh r0, [r1]
	ldr r6, _081FFE84 @ =0x0203B400
	ldr r5, _081FFE88 @ =0x030046B8
	mov r8, r5
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _081FFE8C @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldrh r0, [r3]
	subs r0, #0xf
	movs r5, #0x1f
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	ldr r3, _081FFE90 @ =0x0000025E
	add r3, sb
	ldrh r0, [r3]
	subs r0, #0xf
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r3]
	adds r1, #1
	ands r1, r4
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	movs r2, #0x98
	lsls r2, r2, #2
	add r2, sb
	ldrh r0, [r2]
	subs r0, #0xf
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_081FFE32:
	movs r1, #0x48
	add r1, sb
	mov r8, r1
	ldr r2, _081FFE94 @ =0x00000802
	add r2, sb
	ldrh r0, [r2]
	mov r6, sb
	adds r6, #0x98
	cmp r0, #0
	beq _081FFE64
	movs r0, #4
	ldr r1, [r6]
	orrs r1, r0
	str r1, [r6]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081FFE64
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
_081FFE64:
	movs r2, #0xae
	lsls r2, r2, #1
	adds r4, r7, r2
	movs r1, #4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081FFE98
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	b _081FFF46
	.align 2, 0
_081FFE80: .4byte 0x00000804
_081FFE84: .4byte 0x0203B400
_081FFE88: .4byte 0x030046B8
_081FFE8C: .4byte 0x000003FF
_081FFE90: .4byte 0x0000025E
_081FFE94: .4byte 0x00000802
_081FFE98:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	mov r3, r8
	ldrb r0, [r3, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	add r5, sp, #4
	adds r3, r0, #0
	adds r3, #0x40
	movs r0, #0xa0
	rsbs r0, r0, #0
	mov ip, r0
	ldr r2, _081FFEDC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _081FFEE0
	asrs r1, r0, #0xc
	b _081FFEE6
	.align 2, 0
_081FFEDC: .4byte 0x085B0A08
_081FFEE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081FFEE6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _081FFF06
	asrs r0, r0, #0xc
	b _081FFF0C
_081FFF06:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081FFF0C:
	strh r0, [r5, #4]
	add r2, sp, #4
	mov r3, r8
	adds r3, #8
	adds r0, r2, #0
	ldrh r0, [r0]
	mov r5, r8
	ldrh r5, [r5, #8]
	adds r0, r0, r5
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #0
	bl FUN_082364c4
	mov r2, r8
	ldrb r1, [r2, #5]
	adds r0, r4, #0
	adds r0, #0x42
	strb r1, [r0]
_081FFF46:
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r4, r7, r3
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081FFF98
	ldr r0, _081FFF94 @ =0x03002BE0
	ldr r0, [r0]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #2
	beq _081FFF98
	movs r0, #0x80
	lsls r0, r0, #4
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x20]
	mov r1, r8
	adds r1, #8
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	mov r1, r8
	ldrb r0, [r1, #5]
	movs r3, #0xf7
	lsls r3, r3, #1
	adds r2, r7, r3
	strb r0, [r2]
	adds r0, r4, #0
	bl FUN_08236400
	b _081FFFA2
	.align 2, 0
_081FFF94: .4byte 0x03002BE0
_081FFF98:
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r4, #0x1c]
	strh r0, [r4, #0x1e]
	strh r0, [r4, #0x20]
_081FFFA2:
	movs r1, #0x10
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081FFFBA
	movs r5, #0x8f
	lsls r5, r5, #2
	adds r0, r7, r5
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	b _081FFFC8
_081FFFBA:
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0, #8]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_081FFFC8:
	str r1, [r0, #8]
	movs r2, #0x80
	lsls r2, r2, #4
	adds r1, r7, r2
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08200000
	subs r0, r2, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _081FFFE6
	b _08200152
_081FFFE6:
	ldr r0, _081FFFF8 @ =0x03003584
	ldr r0, [r0]
	ldr r5, _081FFFFC @ =0x00004620
	adds r0, r0, r5
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r1, r7, r2
	str r0, [r1]
	b _08200152
	.align 2, 0
_081FFFF8: .4byte 0x03003584
_081FFFFC: .4byte 0x00004620
_08200000:
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r3, r3, r7
	mov r8, r3
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #2
	beq _08200098
	cmp r0, #2
	bgt _0820001A
	cmp r0, #1
	beq _08200020
	b _08200152
_0820001A:
	cmp r0, #3
	beq _08200110
	b _08200152
_08200020:
	ldr r5, _08200084 @ =0x000007CA
	adds r4, r7, r5
	ldr r0, _08200088 @ =0x00000233
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_081fa620
	adds r1, r0, #0
	ldr r0, _0820008C @ =0x03003584
	lsls r1, r1, #5
	ldr r2, [r0]
	adds r1, r2, r1
	ldrh r0, [r4]
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r0, #0xb9
	lsls r0, r0, #3
	adds r4, r7, r0
	ldr r3, _08200090 @ =0x000007C9
	adds r5, r7, r3
	ldrb r3, [r5]
	movs r0, #7
	str r0, [sp]
	adds r0, r4, #0
	bl rgb555_08237468
	movs r1, #0xa1
	lsls r1, r1, #2
	adds r0, r7, r1
	str r4, [r0]
	ldr r2, _08200094 @ =0x000007CC
	adds r0, r7, r2
	ldr r0, [r0]
	adds r1, r4, #0
	bl FUN_08203c64
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x7e
	bls _08200152
	movs r0, #0x7f
	strb r0, [r5]
	movs r0, #0
	mov r3, r8
	strb r0, [r3]
	b _08200152
	.align 2, 0
_08200084: .4byte 0x000007CA
_08200088: .4byte 0x00000233
_0820008C: .4byte 0x03003584
_08200090: .4byte 0x000007C9
_08200094: .4byte 0x000007CC
_08200098:
	ldr r5, _082000FC @ =0x000007CA
	adds r1, r7, r5
	ldr r0, _08200100 @ =0x00000231
	strh r0, [r1]
	ldr r5, _08200104 @ =0x03003584
	lsls r0, r0, #5
	ldr r4, [r5]
	adds r4, r4, r0
	adds r0, r7, #0
	bl FUN_081fa620
	lsls r0, r0, #5
	ldr r2, [r5]
	adds r2, r2, r0
	movs r0, #0xb9
	lsls r0, r0, #3
	adds r5, r7, r0
	ldr r1, _08200108 @ =0x000007C9
	adds r6, r7, r1
	ldrb r3, [r6]
	movs r0, #7
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl rgb555_08237468
	movs r2, #0xa1
	lsls r2, r2, #2
	adds r0, r7, r2
	str r5, [r0]
	ldr r3, _0820010C @ =0x000007CC
	adds r0, r7, r3
	ldr r0, [r0]
	adds r1, r5, #0
	bl FUN_08203c64
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x7e
	bls _08200152
	movs r0, #0x7f
	strb r0, [r6]
	movs r0, #0
	mov r5, r8
	strb r0, [r5]
	b _08200152
	.align 2, 0
_082000FC: .4byte 0x000007CA
_08200100: .4byte 0x00000231
_08200104: .4byte 0x03003584
_08200108: .4byte 0x000007C9
_0820010C: .4byte 0x000007CC
_08200110:
	ldr r0, _08200190 @ =0x03003584
	ldr r1, [r0]
	ldr r0, _08200194 @ =0x00004720
	adds r1, r1, r0
	movs r2, #0xd9
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, _08200198 @ =0x000007C9
	adds r4, r7, r3
	ldrb r2, [r4]
	movs r3, #0x80
	subs r3, r3, r2
	movs r2, #7
	str r2, [sp]
	movs r2, #0
	bl rgb555_08237510
	movs r5, #0xb9
	lsls r5, r5, #2
	adds r1, r7, r5
	movs r2, #0xb9
	lsls r2, r2, #3
	adds r0, r7, r2
	str r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x7e
	bls _08200152
	movs r0, #0x7f
	strb r0, [r4]
_08200152:
	mov r0, sb
	bl FUN_081ff948
	ldr r3, _0820019C @ =0x000007D2
	adds r0, r7, r3
	movs r1, #0
	movs r2, #0
	strh r2, [r0]
	ldr r5, _082001A0 @ =0x000007DC
	adds r0, r7, r5
	strh r2, [r0]
	adds r3, #0xc
	adds r0, r7, r3
	strb r1, [r0]
	mov r1, sb
	adds r1, #0xe0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	mov r0, sb
	adds r0, #0xb4
	str r2, [r0]
	adds r0, #4
	str r2, [r0]
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200190: .4byte 0x03003584
_08200194: .4byte 0x00004720
_08200198: .4byte 0x000007C9
_0820019C: .4byte 0x000007D2
_082001A0: .4byte 0x000007DC
