	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081eb348
FUN_081eb348: @ 0x081EB348
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	str r0, [sp, #0xc]
	adds r5, r2, #0
	adds r0, #0xd2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081EB364
	bl FUN_081ed2ec
_081EB364:
	ldr r2, [sp, #0xc]
	adds r2, #0xd4
	ldrh r4, [r2]
	ldr r6, [sp, #0xc]
	adds r6, #0x70
	adds r1, #0x20
	asrs r3, r1, #6
	movs r0, #3
	ands r3, r0
	mov sb, r2
	adds r7, r6, #0
	mov r8, r1
	cmp r3, #1
	beq _081EB464
	cmp r3, #1
	bgt _081EB38A
	cmp r3, #0
	beq _081EB398
	b _081EB6A4
_081EB38A:
	cmp r3, #2
	bne _081EB390
	b _081EB52A
_081EB390:
	cmp r3, #3
	bne _081EB396
	b _081EB5E0
_081EB396:
	b _081EB6A4
_081EB398:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB3A8
	adds r0, #4
	b _081EB3B4
_081EB3A8:
	ldr r0, _081EB3D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB3B4:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EB3BE
	b _081EB6A0
_081EB3BE:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB3D4
	adds r0, #4
	b _081EB3E0
	.align 2, 0
_081EB3D0: .4byte 0x030046A4
_081EB3D4:
	ldr r0, _081EB3FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB3E0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EB3EA
	b _081EB6A0
_081EB3EA:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB400
	adds r0, #4
	b _081EB40C
	.align 2, 0
_081EB3FC: .4byte 0x030046A4
_081EB400:
	ldr r0, _081EB428 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB40C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EB418
	b _081EB6A4
_081EB418:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB42C
	adds r0, #4
	b _081EB438
	.align 2, 0
_081EB428: .4byte 0x030046A4
_081EB42C:
	ldr r0, _081EB44C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB438:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EB450
_081EB446:
	cmp r2, #2
	beq _081EB454
	b _081EB458
	.align 2, 0
_081EB44C: .4byte 0x030046A4
_081EB450:
	ldrb r0, [r6, #4]
	b _081EB456
_081EB454:
	ldrb r0, [r6]
_081EB456:
	subs r1, r1, r0
_081EB458:
	movs r2, #2
	ldrsh r0, [r6, r2]
_081EB45C:
	cmp r1, r0
	bne _081EB462
	b _081EB6A0
_081EB462:
	b _081EB6A4
_081EB464:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB474
	adds r0, #4
	b _081EB480
_081EB474:
	ldr r0, _081EB49C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB480:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EB48A
	b _081EB6A0
_081EB48A:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB4A0
	adds r0, #4
	b _081EB4AC
	.align 2, 0
_081EB49C: .4byte 0x030046A4
_081EB4A0:
	ldr r0, _081EB4C8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB4AC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EB4B6
	b _081EB6A0
_081EB4B6:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB4CC
	adds r0, #4
	b _081EB4D8
	.align 2, 0
_081EB4C8: .4byte 0x030046A4
_081EB4CC:
	ldr r0, _081EB4F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB4D8:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EB4E4
	b _081EB6A4
_081EB4E4:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB4F8
	adds r0, #4
	b _081EB504
	.align 2, 0
_081EB4F4: .4byte 0x030046A4
_081EB4F8:
	ldr r0, _081EB518 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB504:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EB51C
	cmp r2, #2
	beq _081EB520
	b _081EB524
	.align 2, 0
_081EB518: .4byte 0x030046A4
_081EB51C:
	ldrb r0, [r6, #4]
	b _081EB522
_081EB520:
	ldrb r0, [r6]
_081EB522:
	subs r1, r1, r0
_081EB524:
	movs r3, #2
	ldrsh r0, [r6, r3]
	b _081EB45C
_081EB52A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB53A
	adds r0, #4
	b _081EB546
_081EB53A:
	ldr r0, _081EB560 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB546:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EB550
	b _081EB6A0
_081EB550:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB564
	adds r0, #4
	b _081EB570
	.align 2, 0
_081EB560: .4byte 0x030046A4
_081EB564:
	ldr r0, _081EB58C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB570:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EB57A
	b _081EB6A0
_081EB57A:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB590
	adds r0, #4
	b _081EB59C
	.align 2, 0
_081EB58C: .4byte 0x030046A4
_081EB590:
	ldr r0, _081EB5B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB59C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EB5A8
	b _081EB6A4
_081EB5A8:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB5BC
	adds r0, #4
	b _081EB5C8
	.align 2, 0
_081EB5B8: .4byte 0x030046A4
_081EB5BC:
	ldr r0, _081EB5DC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB5C8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EB5D8
	b _081EB446
_081EB5D8:
	ldrb r0, [r6, #4]
	b _081EB456
	.align 2, 0
_081EB5DC: .4byte 0x030046A4
_081EB5E0:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB5F0
	adds r0, #4
	b _081EB5FC
_081EB5F0:
	ldr r0, _081EB614 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB5FC:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	beq _081EB6A0
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB618
	adds r0, #4
	b _081EB624
	.align 2, 0
_081EB614: .4byte 0x030046A4
_081EB618:
	ldr r0, _081EB63C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB624:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	beq _081EB6A0
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB640
	adds r0, #4
	b _081EB64C
	.align 2, 0
_081EB63C: .4byte 0x030046A4
_081EB640:
	ldr r0, _081EB668 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB64C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EB6A4
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB66C
	adds r0, #4
	b _081EB678
	.align 2, 0
_081EB668: .4byte 0x030046A4
_081EB66C:
	ldr r0, _081EB68C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EB678:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EB690
	cmp r2, #2
	beq _081EB694
	b _081EB698
	.align 2, 0
_081EB68C: .4byte 0x030046A4
_081EB690:
	ldrb r0, [r6, #4]
	b _081EB696
_081EB694:
	ldrb r0, [r6]
_081EB696:
	subs r1, r1, r0
_081EB698:
	movs r3, #2
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bne _081EB6A4
_081EB6A0:
	movs r0, #1
	b _081EB6A6
_081EB6A4:
	movs r0, #0
_081EB6A6:
	cmp r0, #0
	beq _081EB6AE
	bl _081ED63A
_081EB6AE:
	ldr r0, _081EB6E0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081EB6C0
	bl FUN_081ec3f4
_081EB6C0:
	mov r0, sb
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	mov r2, r8
	asrs r1, r2, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bne _081EB6D4
	b _081EBDCE
_081EB6D4:
	cmp r1, #1
	bgt _081EB6E4
	cmp r1, #0
	beq _081EB6F2
	bl _081ED62E
	.align 2, 0
_081EB6E0: .4byte 0x030047A4
_081EB6E4:
	cmp r1, #2
	beq _081EB6F2
	cmp r1, #3
	bne _081EB6EE
	b _081EBDCE
_081EB6EE:
	bl _081ED62E
_081EB6F2:
	ldr r5, _081EB750 @ =0x030046A4
	ldr r0, [r5]
	ldr r1, [r0, #4]
	movs r3, #4
	ldrsh r2, [r1, r3]
	ldr r0, [sp, #0x10]
	subs r0, r0, r2
	mov sb, r0
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov sl, r0
	movs r3, #6
	ldrsh r0, [r1, r3]
	adds r1, r2, #0
	muls r1, r0, r1
	str r1, [sp, #0x14]
	ldr r3, [sp, #0x10]
	cmp r3, sb
	blt _081EB71C
	b _081EB8C6
_081EB71C:
	adds r4, r3, #0
	adds r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _081EB7F2
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EB73E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB754
	adds r0, #4
	b _081EB75C
	.align 2, 0
_081EB750: .4byte 0x030046A4
_081EB754:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB75C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081EB7F2
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB776
	adds r0, #4
	b _081EB77E
_081EB776:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB77E:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EB7F2
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB798
	adds r0, #4
	b _081EB7A0
_081EB798:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB7A0:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EB7D8
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB7B8
	adds r0, #4
	b _081EB7C0
_081EB7B8:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB7C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EB7D4
	b _081EBA2C
_081EB7D4:
	ldrb r0, [r7, #4]
	b _081EBA38
_081EB7D8:
	cmp r4, sb
	bne _081EB7DE
	b _081EBA3C
_081EB7DE:
	adds r5, #4
	adds r4, #1
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081EB73E
_081EB7F2:
	ldr r1, _081EB81C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x10]
	adds r4, r2, r0
	ldr r3, [sp, #0x14]
	cmp r3, r4
	bgt _081EB808
	b _081EBA52
_081EB808:
	adds r5, r1, #0
	movs r6, #0xf
_081EB80C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB820
	adds r0, #4
	b _081EB82A
	.align 2, 0
_081EB81C: .4byte 0x030046A4
_081EB820:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EB82A:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	beq _081EB836
	b _081EBA52
_081EB836:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB846
	adds r0, #4
	b _081EB850
_081EB846:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EB850:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EB85C
	b _081EBA52
_081EB85C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB86C
	adds r0, #4
	b _081EB876
_081EB86C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EB876:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EB8AE
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB88E
	adds r0, #4
	b _081EB898
_081EB88E:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EB898:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EB8AA
	b _081EBA2C
_081EB8AA:
	ldrb r0, [r7, #4]
	b _081EBA38
_081EB8AE:
	cmp r4, sb
	bne _081EB8B4
	b _081EBA3C
_081EB8B4:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	ldr r2, [sp, #0x14]
	cmp r2, r4
	bgt _081EB80C
	b _081EBA52
_081EB8C6:
	ldr r4, [sp, #0x10]
	subs r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	cmp r6, #0
	blt _081EB97E
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EB8E0:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB8F0
	adds r0, #4
	b _081EB8F8
_081EB8F0:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB8F8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081EB97E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB912
	adds r0, #4
	b _081EB91A
_081EB912:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB91A:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EB97E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB934
	adds r0, #4
	b _081EB93C
_081EB934:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB93C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EB970
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB954
	adds r0, #4
	b _081EB95C
_081EB954:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EB95C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r2, r0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081EBA2C
	ldrb r0, [r7, #4]
	b _081EBA38
_081EB970:
	cmp r4, sb
	beq _081EBA3C
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081EB8E0
_081EB97E:
	ldr r1, _081EB9A4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x10]
	subs r4, r3, r0
	cmp r4, #0
	blt _081EBA52
	adds r5, r1, #0
	movs r6, #0xf
_081EB994:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB9A8
	adds r0, #4
	b _081EB9B2
	.align 2, 0
_081EB9A4: .4byte 0x030046A4
_081EB9A8:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EB9B2:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	bne _081EBA52
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB9CC
	adds r0, #4
	b _081EB9D6
_081EB9CC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EB9D6:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EBA52
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EB9F0
	adds r0, #4
	b _081EB9FA
_081EB9F0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EB9FA:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EBA40
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBA12
	adds r0, #4
	b _081EBA1C
_081EBA12:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBA1C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EBA32
_081EBA2C:
	cmp r2, #2
	beq _081EBA36
	b _081EBA3A
_081EBA32:
	ldrb r0, [r7, #4]
	b _081EBA38
_081EBA36:
	ldrb r0, [r7]
_081EBA38:
	subs r1, r1, r0
_081EBA3A:
	strh r1, [r7, #2]
_081EBA3C:
	movs r0, #1
	b _081EBA54
_081EBA40:
	cmp r4, sb
	beq _081EBA3C
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _081EB994
_081EBA52:
	movs r0, #0
_081EBA54:
	cmp r0, #0
	beq _081EBA5E
	movs r4, #3
	bl _081ED28E
_081EBA5E:
	ldr r5, _081EBABC @ =0x030046A4
	ldr r0, [r5]
	ldr r1, [r0, #4]
	movs r3, #4
	ldrsh r2, [r1, r3]
	ldr r0, [sp, #0x10]
	adds r0, r0, r2
	mov sb, r0
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov sl, r0
	movs r3, #6
	ldrsh r0, [r1, r3]
	adds r1, r2, #0
	muls r1, r0, r1
	str r1, [sp, #0x18]
	ldr r3, [sp, #0x10]
	cmp r3, sb
	blt _081EBA88
	b _081EBC32
_081EBA88:
	adds r4, r3, #0
	adds r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	cmp r6, r0
	bge _081EBB5E
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EBAAA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBAC0
	adds r0, #4
	b _081EBAC8
	.align 2, 0
_081EBABC: .4byte 0x030046A4
_081EBAC0:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBAC8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081EBB5E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBAE2
	adds r0, #4
	b _081EBAEA
_081EBAE2:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBAEA:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EBB5E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBB04
	adds r0, #4
	b _081EBB0C
_081EBB04:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBB0C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EBB44
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBB24
	adds r0, #4
	b _081EBB2C
_081EBB24:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBB2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EBB40
	b _081EBD98
_081EBB40:
	ldrb r0, [r7, #4]
	b _081EBDA4
_081EBB44:
	cmp r4, sb
	bne _081EBB4A
	b _081EBDA8
_081EBB4A:
	adds r5, #4
	adds r4, #1
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081EBAAA
_081EBB5E:
	ldr r1, _081EBB88 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x10]
	adds r4, r2, r0
	ldr r3, [sp, #0x18]
	cmp r3, r4
	bgt _081EBB74
	b _081EBDBE
_081EBB74:
	adds r5, r1, #0
	movs r6, #0xf
_081EBB78:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBB8C
	adds r0, #4
	b _081EBB96
	.align 2, 0
_081EBB88: .4byte 0x030046A4
_081EBB8C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBB96:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	beq _081EBBA2
	b _081EBDBE
_081EBBA2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBBB2
	adds r0, #4
	b _081EBBBC
_081EBBB2:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBBBC:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EBBC8
	b _081EBDBE
_081EBBC8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBBD8
	adds r0, #4
	b _081EBBE2
_081EBBD8:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBBE2:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EBC1A
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBBFA
	adds r0, #4
	b _081EBC04
_081EBBFA:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBC04:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EBC16
	b _081EBD98
_081EBC16:
	ldrb r0, [r7, #4]
	b _081EBDA4
_081EBC1A:
	cmp r4, sb
	bne _081EBC20
	b _081EBDA8
_081EBC20:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	ldr r2, [sp, #0x18]
	cmp r2, r4
	bgt _081EBB78
	b _081EBDBE
_081EBC32:
	ldr r4, [sp, #0x10]
	subs r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	cmp r6, #0
	blt _081EBCEA
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EBC4C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBC5C
	adds r0, #4
	b _081EBC64
_081EBC5C:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBC64:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081EBCEA
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBC7E
	adds r0, #4
	b _081EBC86
_081EBC7E:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBC86:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EBCEA
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBCA0
	adds r0, #4
	b _081EBCA8
_081EBCA0:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBCA8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EBCDC
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBCC0
	adds r0, #4
	b _081EBCC8
_081EBCC0:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBCC8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r2, r0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081EBD98
	ldrb r0, [r7, #4]
	b _081EBDA4
_081EBCDC:
	cmp r4, sb
	beq _081EBDA8
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081EBC4C
_081EBCEA:
	ldr r1, _081EBD10 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x10]
	subs r4, r3, r0
	cmp r4, #0
	blt _081EBDBE
	adds r5, r1, #0
	movs r6, #0xf
_081EBD00:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBD14
	adds r0, #4
	b _081EBD1E
	.align 2, 0
_081EBD10: .4byte 0x030046A4
_081EBD14:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBD1E:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	bne _081EBDBE
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBD38
	adds r0, #4
	b _081EBD42
_081EBD38:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBD42:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EBDBE
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBD5C
	adds r0, #4
	b _081EBD66
_081EBD5C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBD66:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EBDAC
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBD7E
	adds r0, #4
	b _081EBD88
_081EBD7E:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBD88:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EBD9E
_081EBD98:
	cmp r2, #2
	beq _081EBDA2
	b _081EBDA6
_081EBD9E:
	ldrb r0, [r7, #4]
	b _081EBDA4
_081EBDA2:
	ldrb r0, [r7]
_081EBDA4:
	subs r1, r1, r0
_081EBDA6:
	strh r1, [r7, #2]
_081EBDA8:
	movs r0, #1
	b _081EBDC0
_081EBDAC:
	cmp r4, sb
	beq _081EBDA8
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _081EBD00
_081EBDBE:
	movs r0, #0
_081EBDC0:
	cmp r0, #0
	bne _081EBDC8
	bl _081ED62E
_081EBDC8:
	movs r4, #1
	bl _081ED28E
_081EBDCE:
	ldr r2, [sp, #0x10]
	adds r2, #1
	mov sb, r2
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	str r0, [sp, #0x1c]
	ldr r5, _081EBE30 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r3, r1, #0
	muls r3, r0, r3
	str r3, [sp, #0x20]
	mov r0, sb
	str r0, [sp, #0x44]
	ldr r2, [sp, #0x10]
	cmp r2, sb
	blt _081EBDFC
	b _081EBFAC
_081EBDFC:
	mov r4, sb
	bl Mod
	adds r6, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	cmp r6, r0
	bge _081EBED4
	mov r8, r5
	mov r1, sb
	lsls r0, r1, #2
	adds r5, r0, #0
	adds r5, #0xc
	movs r2, #0xf
	mov sl, r2
_081EBE1E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBE34
	adds r0, #4
	b _081EBE3C
	.align 2, 0
_081EBE30: .4byte 0x030046A4
_081EBE34:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBE3C:
	ldrb r1, [r0]
	mov r0, sl
	ands r0, r1
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	bne _081EBED4
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBE58
	adds r0, #4
	b _081EBE60
_081EBE58:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBE60:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EBED4
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBE7A
	adds r0, #4
	b _081EBE82
_081EBE7A:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBE82:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EBEBA
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBE9A
	adds r0, #4
	b _081EBEA2
_081EBE9A:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBEA2:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	mov r3, sl
	ands r2, r3
	mov r0, sl
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EBEB6
	b _081EC11A
_081EBEB6:
	ldrb r0, [r7, #4]
	b _081EC126
_081EBEBA:
	cmp r4, sb
	bne _081EBEC0
	b _081EC12A
_081EBEC0:
	adds r5, #4
	adds r4, #1
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081EBE1E
_081EBED4:
	ldr r1, _081EBF00 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x10]
	adds r4, r2, r0
	ldr r3, [sp, #0x20]
	cmp r3, r4
	bgt _081EBEEA
	b _081EC140
_081EBEEA:
	adds r5, r1, #0
	movs r6, #0xf
_081EBEEE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBF04
	adds r0, #4
	b _081EBF0E
	.align 2, 0
_081EBF00: .4byte 0x030046A4
_081EBF04:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBF0E:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	beq _081EBF1C
	b _081EC140
_081EBF1C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBF2C
	adds r0, #4
	b _081EBF36
_081EBF2C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBF36:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EBF42
	b _081EC140
_081EBF42:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBF52
	adds r0, #4
	b _081EBF5C
_081EBF52:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBF5C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EBF94
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBF74
	adds r0, #4
	b _081EBF7E
_081EBF74:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EBF7E:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EBF90
	b _081EC11A
_081EBF90:
	ldrb r0, [r7, #4]
	b _081EC126
_081EBF94:
	cmp r4, sb
	bne _081EBF9A
	b _081EC12A
_081EBF9A:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r4, r0
	ldr r3, [sp, #0x20]
	cmp r3, r4
	bgt _081EBEEE
	b _081EC140
_081EBFAC:
	ldr r4, [sp, #0x10]
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r6, r0, #0
	cmp r6, #0
	blt _081EC06A
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
	movs r0, #0xf
	mov sl, r0
_081EBFC8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBFD8
	adds r0, #4
	b _081EBFE0
_081EBFD8:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EBFE0:
	ldrb r1, [r0]
	mov r0, sl
	ands r0, r1
	ldr r2, [sp, #0x1c]
	cmp r0, r2
	bne _081EC06A
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EBFFC
	adds r0, #4
	b _081EC004
_081EBFFC:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC004:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC06A
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC01E
	adds r0, #4
	b _081EC026
_081EC01E:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC026:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EC05C
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC03E
	adds r0, #4
	b _081EC046
_081EC03E:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC046:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	mov r3, sl
	ands r2, r3
	mov r0, sl
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081EC11A
	ldrb r0, [r7, #4]
	b _081EC126
_081EC05C:
	cmp r4, sb
	beq _081EC12A
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081EBFC8
_081EC06A:
	ldr r1, _081EC090 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x10]
	subs r4, r3, r0
	cmp r4, #0
	blt _081EC140
	adds r5, r1, #0
	movs r6, #0xf
_081EC080:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC094
	adds r0, #4
	b _081EC09E
	.align 2, 0
_081EC090: .4byte 0x030046A4
_081EC094:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC09E:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	bne _081EC140
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC0BA
	adds r0, #4
	b _081EC0C4
_081EC0BA:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC0C4:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC140
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC0DE
	adds r0, #4
	b _081EC0E8
_081EC0DE:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC0E8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EC12E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC100
	adds r0, #4
	b _081EC10A
_081EC100:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC10A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EC120
_081EC11A:
	cmp r2, #2
	beq _081EC124
	b _081EC128
_081EC120:
	ldrb r0, [r7, #4]
	b _081EC126
_081EC124:
	ldrb r0, [r7]
_081EC126:
	subs r1, r1, r0
_081EC128:
	strh r1, [r7, #2]
_081EC12A:
	movs r0, #1
	b _081EC142
_081EC12E:
	cmp r4, sb
	beq _081EC12A
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
	cmp r4, #0
	bge _081EC080
_081EC140:
	movs r0, #0
_081EC142:
	cmp r0, #0
	beq _081EC14C
	movs r4, #0
	bl _081ED28E
_081EC14C:
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	str r0, [sp, #0x24]
	ldr r5, _081EC170 @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r3, r1, #0
	muls r3, r0, r3
	str r3, [sp, #0x28]
	ldr r0, [sp, #0x10]
	subs r0, #1
	mov sb, r0
	b _081EC250
	.align 2, 0
_081EC170: .4byte 0x030046A4
_081EC174:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrb r1, [r0]
	mov r0, sl
	ands r0, r1
	ldr r1, [sp, #0x24]
	cmp r0, r1
	bne _081EC1D2
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC1D2
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EC1BC
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrb r1, [r0]
	lsrs r2, r1, #4
	mov r3, sl
	ands r2, r3
	b _081EC230
_081EC1BC:
	cmp r4, sb
	bne _081EC1C2
	b _081EC3E6
_081EC1C2:
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081EC174
_081EC1D2:
	ldr r1, _081EC234 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x10]
	adds r4, r2, r0
	ldr r3, [sp, #0x28]
	cmp r3, r4
	bgt _081EC1E8
	b _081EC3E6
_081EC1E8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	ldr r1, [sp, #0x24]
	cmp r0, r1
	beq _081EC1FE
	b _081EC3E6
_081EC1FE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EC212
	b _081EC3E6
_081EC212:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EC238
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
_081EC230:
	strh r1, [r7, #2]
	b _081EC3E6
	.align 2, 0
_081EC234: .4byte 0x030046A4
_081EC238:
	cmp r4, sb
	bne _081EC23E
	b _081EC3E6
_081EC23E:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	adds r4, r4, r0
	ldr r3, [sp, #0x28]
	cmp r3, r4
	bgt _081EC1E8
	b _081EC3E6
_081EC250:
	mov r4, sb
	adds r0, r4, #0
	bl Mod
	adds r6, r0, #0
	cmp r6, #0
	blt _081EC30C
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
	movs r0, #0xf
	mov sl, r0
_081EC26A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC27A
	adds r0, #4
	b _081EC282
_081EC27A:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC282:
	ldrb r1, [r0]
	mov r0, sl
	ands r0, r1
	ldr r2, [sp, #0x24]
	cmp r0, r2
	bne _081EC30C
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC29E
	adds r0, #4
	b _081EC2A6
_081EC29E:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC2A6:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC30C
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC2C0
	adds r0, #4
	b _081EC2C8
_081EC2C0:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC2C8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EC2FE
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC2E0
	adds r0, #4
	b _081EC2E8
_081EC2E0:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC2E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	mov r3, sl
	ands r2, r3
	mov r0, sl
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081EC3BE
	ldrb r0, [r7, #4]
	b _081EC3CA
_081EC2FE:
	cmp r4, sb
	beq _081EC3CE
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081EC26A
_081EC30C:
	ldr r1, _081EC334 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x10]
	subs r4, r3, r0
	cmp r4, #0
	blt _081EC3E4
	adds r5, r1, #0
	movs r6, #0xf
_081EC322:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC338
	adds r0, #4
	b _081EC342
	.align 2, 0
_081EC334: .4byte 0x030046A4
_081EC338:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC342:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	ldr r1, [sp, #0x24]
	cmp r0, r1
	bne _081EC3E4
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC35E
	adds r0, #4
	b _081EC368
_081EC35E:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC368:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC3E4
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC382
	adds r0, #4
	b _081EC38C
_081EC382:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC38C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EC3D2
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC3A4
	adds r0, #4
	b _081EC3AE
_081EC3A4:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC3AE:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EC3C4
_081EC3BE:
	cmp r2, #2
	beq _081EC3C8
	b _081EC3CC
_081EC3C4:
	ldrb r0, [r7, #4]
	b _081EC3CA
_081EC3C8:
	ldrb r0, [r7]
_081EC3CA:
	subs r1, r1, r0
_081EC3CC:
	strh r1, [r7, #2]
_081EC3CE:
	movs r1, #1
	b _081EC3E6
_081EC3D2:
	cmp r4, sb
	beq _081EC3CE
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r4, r4, r0
	cmp r4, #0
	bge _081EC322
_081EC3E4:
	movs r1, #0
_081EC3E6:
	movs r4, #2
	cmp r1, #0
	beq _081EC3F0
	bl _081ED288
_081EC3F0:
	bl _081ED62E

	thumb_func_start FUN_081ec3f4
FUN_081ec3f4: @ 0x081EC3F4
	mov r3, sb
	ldrh r3, [r3]
	str r3, [sp, #0x2c]
	mov r0, r8
	asrs r4, r0, #6
	movs r0, #3
	ands r4, r0
	ldr r0, _081EC410 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	bne _081EC414
	movs r1, #0
	str r1, [sp, #0x30]
	b _081EC448
	.align 2, 0
_081EC410: .4byte 0x03002BE0
_081EC414:
	add r2, sp, #4
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	str r0, [sp, #0x30]
_081EC448:
	mov r0, sp
	movs r1, #4
	bl ClearMemory
	cmp r4, #1
	bne _081EC456
	b _081ECB72
_081EC456:
	cmp r4, #1
	bgt _081EC468
	cmp r4, #0
	beq _081EC47C
	ldr r0, [sp, #0x30]
	add r0, sp
	str r0, [sp, #0x48]
	bl _081ED262
_081EC468:
	cmp r4, #2
	beq _081EC47C
	cmp r4, #3
	bne _081EC472
	b _081ECB72
_081EC472:
	ldr r1, [sp, #0x30]
	add r1, sp
	str r1, [sp, #0x48]
	bl _081ED262
_081EC47C:
	ldr r5, _081EC4E0 @ =0x030046A4
	ldr r0, [r5]
	ldr r1, [r0, #4]
	movs r3, #4
	ldrsh r2, [r1, r3]
	ldr r0, [sp, #0x2c]
	subs r0, r0, r2
	mov sb, r0
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov sl, r0
	movs r3, #6
	ldrsh r0, [r1, r3]
	adds r1, r2, #0
	muls r1, r0, r1
	str r1, [sp, #0x34]
	ldr r3, [sp, #0x2c]
	cmp r3, sb
	blt _081EC4A6
	b _081EC656
_081EC4A6:
	adds r4, r3, #0
	adds r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	ldr r2, [sp, #0x30]
	add r2, sp
	str r2, [sp, #0x48]
	cmp r6, r0
	bge _081EC580
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EC4CE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC4E4
	adds r0, #4
	b _081EC4EC
	.align 2, 0
_081EC4E0: .4byte 0x030046A4
_081EC4E4:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC4EC:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081EC580
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC506
	adds r0, #4
	b _081EC50E
_081EC506:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC50E:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC580
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC528
	adds r0, #4
	b _081EC530
_081EC528:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC530:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EC566
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC548
	adds r0, #4
	b _081EC550
_081EC548:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC550:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r2, r0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EC562
	b _081EC7C4
_081EC562:
	ldrb r0, [r7, #4]
	b _081EC7D0
_081EC566:
	cmp r4, sb
	bne _081EC56C
	b _081EC7D4
_081EC56C:
	adds r5, #4
	adds r4, #1
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081EC4CE
_081EC580:
	ldr r1, _081EC5AC @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x2c]
	adds r4, r2, r0
	ldr r3, [sp, #0x34]
	cmp r3, r4
	bgt _081EC596
	b _081EC7EA
_081EC596:
	adds r5, r1, #0
	movs r6, #0xf
_081EC59A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC5B0
	adds r0, #4
	b _081EC5BA
	.align 2, 0
_081EC5AC: .4byte 0x030046A4
_081EC5B0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC5BA:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	beq _081EC5C6
	b _081EC7EA
_081EC5C6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC5D6
	adds r0, #4
	b _081EC5E0
_081EC5D6:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC5E0:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EC5EC
	b _081EC7EA
_081EC5EC:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC5FC
	adds r0, #4
	b _081EC606
_081EC5FC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC606:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EC63E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC61E
	adds r0, #4
	b _081EC628
_081EC61E:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC628:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EC63A
	b _081EC7C4
_081EC63A:
	ldrb r0, [r7, #4]
	b _081EC7D0
_081EC63E:
	cmp r4, sb
	bne _081EC644
	b _081EC7D4
_081EC644:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	ldr r2, [sp, #0x34]
	cmp r2, r4
	bgt _081EC59A
	b _081EC7EA
_081EC656:
	ldr r4, [sp, #0x2c]
	subs r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	ldr r3, [sp, #0x30]
	add r3, sp
	str r3, [sp, #0x48]
	cmp r6, #0
	blt _081EC716
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EC676:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC686
	adds r0, #4
	b _081EC68E
_081EC686:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC68E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081EC716
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC6A8
	adds r0, #4
	b _081EC6B0
_081EC6A8:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC6B0:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC716
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC6CA
	adds r0, #4
	b _081EC6D2
_081EC6CA:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC6D2:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EC708
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC6EA
	adds r0, #4
	b _081EC6F2
_081EC6EA:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC6F2:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081EC7C4
	ldrb r0, [r7, #4]
	b _081EC7D0
_081EC708:
	cmp r4, sb
	beq _081EC7D4
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081EC676
_081EC716:
	ldr r1, _081EC73C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x2c]
	subs r4, r3, r0
	cmp r4, #0
	blt _081EC7EA
	adds r5, r1, #0
	movs r6, #0xf
_081EC72C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC740
	adds r0, #4
	b _081EC74A
	.align 2, 0
_081EC73C: .4byte 0x030046A4
_081EC740:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC74A:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	bne _081EC7EA
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC764
	adds r0, #4
	b _081EC76E
_081EC764:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC76E:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC7EA
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC788
	adds r0, #4
	b _081EC792
_081EC788:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC792:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EC7D8
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC7AA
	adds r0, #4
	b _081EC7B4
_081EC7AA:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC7B4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EC7CA
_081EC7C4:
	cmp r2, #2
	beq _081EC7CE
	b _081EC7D2
_081EC7CA:
	ldrb r0, [r7, #4]
	b _081EC7D0
_081EC7CE:
	ldrb r0, [r7]
_081EC7D0:
	subs r1, r1, r0
_081EC7D2:
	strh r1, [r7, #2]
_081EC7D4:
	movs r0, #1
	b _081EC7EC
_081EC7D8:
	cmp r4, sb
	beq _081EC7D4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _081EC72C
_081EC7EA:
	movs r0, #0
_081EC7EC:
	cmp r0, #0
	beq _081EC7F6
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #3]
_081EC7F6:
	ldr r2, _081EC854 @ =0x030046A4
	ldr r0, [r2]
	ldr r1, [r0, #4]
	movs r3, #4
	ldrsh r2, [r1, r3]
	ldr r0, [sp, #0x2c]
	adds r0, r0, r2
	mov sb, r0
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov sl, r0
	movs r3, #6
	ldrsh r0, [r1, r3]
	adds r1, r2, #0
	muls r1, r0, r1
	str r1, [sp, #0x38]
	ldr r3, [sp, #0x2c]
	cmp r3, sb
	blt _081EC820
	b _081EC9CA
_081EC820:
	adds r4, r3, #0
	adds r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	ldr r1, _081EC854 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _081EC8F4
	mov r8, r1
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EC844:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC858
	adds r0, #4
	b _081EC860
	.align 2, 0
_081EC854: .4byte 0x030046A4
_081EC858:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC860:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081EC8F4
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC87A
	adds r0, #4
	b _081EC882
_081EC87A:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC882:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081EC8F4
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC89C
	adds r0, #4
	b _081EC8A4
_081EC89C:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC8A4:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081EC8DA
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC8BC
	adds r0, #4
	b _081EC8C4
_081EC8BC:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081EC8C4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r2, r0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EC8D6
	b _081ECB3C
_081EC8D6:
	ldrb r0, [r7, #4]
	b _081ECB48
_081EC8DA:
	cmp r4, sb
	bne _081EC8E0
	b _081ECB4C
_081EC8E0:
	adds r5, #4
	adds r4, #1
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081EC844
_081EC8F4:
	ldr r1, _081EC920 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x2c]
	adds r4, r2, r0
	ldr r3, [sp, #0x38]
	cmp r3, r4
	bgt _081EC90A
	b _081ECB62
_081EC90A:
	adds r5, r1, #0
	movs r6, #0xf
_081EC90E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC924
	adds r0, #4
	b _081EC92E
	.align 2, 0
_081EC920: .4byte 0x030046A4
_081EC924:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC92E:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	beq _081EC93A
	b _081ECB62
_081EC93A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC94A
	adds r0, #4
	b _081EC954
_081EC94A:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC954:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081EC960
	b _081ECB62
_081EC960:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC970
	adds r0, #4
	b _081EC97A
_081EC970:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC97A:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081EC9B2
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC992
	adds r0, #4
	b _081EC99C
_081EC992:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081EC99C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EC9AE
	b _081ECB3C
_081EC9AE:
	ldrb r0, [r7, #4]
	b _081ECB48
_081EC9B2:
	cmp r4, sb
	bne _081EC9B8
	b _081ECB4C
_081EC9B8:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	ldr r2, [sp, #0x38]
	cmp r2, r4
	bgt _081EC90E
	b _081ECB62
_081EC9CA:
	ldr r4, [sp, #0x2c]
	subs r4, #1
	adds r0, r4, #0
	adds r1, r2, #0
	bl Mod
	adds r6, r0, #0
	cmp r6, #0
	blt _081ECA8C
	ldr r3, _081EC9F8 @ =0x030046A4
	mov r8, r3
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081EC9E6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EC9FC
	adds r0, #4
	b _081ECA04
	.align 2, 0
_081EC9F8: .4byte 0x030046A4
_081EC9FC:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECA04:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081ECA8C
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECA1E
	adds r0, #4
	b _081ECA26
_081ECA1E:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECA26:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ECA8C
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECA40
	adds r0, #4
	b _081ECA48
_081ECA40:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECA48:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ECA7E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECA60
	adds r0, #4
	b _081ECA68
_081ECA60:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECA68:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081ECB3C
	ldrb r0, [r7, #4]
	b _081ECB48
_081ECA7E:
	cmp r4, sb
	beq _081ECB4C
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081EC9E6
_081ECA8C:
	ldr r1, _081ECAB4 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x2c]
	subs r4, r3, r0
	cmp r4, #0
	blt _081ECB62
	adds r5, r1, #0
	movs r6, #0xf
_081ECAA2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECAB8
	adds r0, #4
	b _081ECAC2
	.align 2, 0
_081ECAB4: .4byte 0x030046A4
_081ECAB8:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECAC2:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	bne _081ECB62
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECADC
	adds r0, #4
	b _081ECAE6
_081ECADC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECAE6:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ECB62
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECB00
	adds r0, #4
	b _081ECB0A
_081ECB00:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECB0A:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081ECB50
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECB22
	adds r0, #4
	b _081ECB2C
_081ECB22:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECB2C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ECB42
_081ECB3C:
	cmp r2, #2
	beq _081ECB46
	b _081ECB4A
_081ECB42:
	ldrb r0, [r7, #4]
	b _081ECB48
_081ECB46:
	ldrb r0, [r7]
_081ECB48:
	subs r1, r1, r0
_081ECB4A:
	strh r1, [r7, #2]
_081ECB4C:
	movs r0, #1
	b _081ECB64
_081ECB50:
	cmp r4, sb
	beq _081ECB4C
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _081ECAA2
_081ECB62:
	movs r0, #0
_081ECB64:
	cmp r0, #0
	bne _081ECB6A
	b _081ED262
_081ECB6A:
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #1]
	b _081ED262
_081ECB72:
	ldr r2, [sp, #0x2c]
	adds r2, #1
	mov sb, r2
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov sl, r0
	ldr r5, _081ECBDC @ =0x030046A4
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	movs r2, #6
	ldrsh r0, [r0, r2]
	adds r3, r1, #0
	muls r3, r0, r3
	str r3, [sp, #0x3c]
	mov r0, sb
	str r0, [sp, #0x50]
	ldr r2, [sp, #0x2c]
	cmp r2, sb
	blt _081ECBA0
	b _081ECD52
_081ECBA0:
	mov r4, sb
	bl Mod
	adds r6, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r1, [sp, #0x2c]
	subs r1, #1
	str r1, [sp, #0x4c]
	ldr r2, [sp, #0x30]
	add r2, sp
	str r2, [sp, #0x48]
	cmp r6, r0
	bge _081ECC7E
	mov r8, r5
	mov r3, sb
	lsls r0, r3, #2
	adds r5, r0, #0
	adds r5, #0xc
_081ECBCA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECBE0
	adds r0, #4
	b _081ECBE8
	.align 2, 0
_081ECBDC: .4byte 0x030046A4
_081ECBE0:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECBE8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081ECC7E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECC02
	adds r0, #4
	b _081ECC0A
_081ECC02:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECC0A:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ECC7E
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECC24
	adds r0, #4
	b _081ECC2C
_081ECC24:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECC2C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ECC64
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECC44
	adds r0, #4
	b _081ECC4C
_081ECC44:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECC4C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ECC60
	b _081ECEC0
_081ECC60:
	ldrb r0, [r7, #4]
	b _081ECECC
_081ECC64:
	cmp r4, sb
	bne _081ECC6A
	b _081ECED0
_081ECC6A:
	adds r5, #4
	adds r4, #1
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081ECBCA
_081ECC7E:
	ldr r1, _081ECCA8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x2c]
	adds r4, r2, r0
	ldr r3, [sp, #0x3c]
	cmp r3, r4
	bgt _081ECC94
	b _081ECEE6
_081ECC94:
	adds r5, r1, #0
	movs r6, #0xf
_081ECC98:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECCAC
	adds r0, #4
	b _081ECCB6
	.align 2, 0
_081ECCA8: .4byte 0x030046A4
_081ECCAC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECCB6:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	beq _081ECCC2
	b _081ECEE6
_081ECCC2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECCD2
	adds r0, #4
	b _081ECCDC
_081ECCD2:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECCDC:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081ECCE8
	b _081ECEE6
_081ECCE8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECCF8
	adds r0, #4
	b _081ECD02
_081ECCF8:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECD02:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081ECD3A
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECD1A
	adds r0, #4
	b _081ECD24
_081ECD1A:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECD24:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ECD36
	b _081ECEC0
_081ECD36:
	ldrb r0, [r7, #4]
	b _081ECECC
_081ECD3A:
	cmp r4, sb
	bne _081ECD40
	b _081ECED0
_081ECD40:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	ldr r2, [sp, #0x3c]
	cmp r2, r4
	bgt _081ECC98
	b _081ECEE6
_081ECD52:
	ldr r4, [sp, #0x2c]
	subs r4, #1
	adds r0, r4, #0
	bl Mod
	adds r6, r0, #0
	str r4, [sp, #0x4c]
	ldr r3, [sp, #0x30]
	add r3, sp
	str r3, [sp, #0x48]
	cmp r6, #0
	blt _081ECE12
	mov r8, r5
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081ECD72:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECD82
	adds r0, #4
	b _081ECD8A
_081ECD82:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECD8A:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081ECE12
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECDA4
	adds r0, #4
	b _081ECDAC
_081ECDA4:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECDAC:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ECE12
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECDC6
	adds r0, #4
	b _081ECDCE
_081ECDC6:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECDCE:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ECE04
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECDE6
	adds r0, #4
	b _081ECDEE
_081ECDE6:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECDEE:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081ECEC0
	ldrb r0, [r7, #4]
	b _081ECECC
_081ECE04:
	cmp r4, sb
	beq _081ECED0
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081ECD72
_081ECE12:
	ldr r1, _081ECE38 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x2c]
	subs r4, r3, r0
	cmp r4, #0
	blt _081ECEE6
	adds r5, r1, #0
	movs r6, #0xf
_081ECE28:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECE3C
	adds r0, #4
	b _081ECE46
	.align 2, 0
_081ECE38: .4byte 0x030046A4
_081ECE3C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECE46:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	bne _081ECEE6
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECE60
	adds r0, #4
	b _081ECE6A
_081ECE60:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECE6A:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ECEE6
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECE84
	adds r0, #4
	b _081ECE8E
_081ECE84:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECE8E:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081ECED4
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECEA6
	adds r0, #4
	b _081ECEB0
_081ECEA6:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ECEB0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ECEC6
_081ECEC0:
	cmp r2, #2
	beq _081ECECA
	b _081ECECE
_081ECEC6:
	ldrb r0, [r7, #4]
	b _081ECECC
_081ECECA:
	ldrb r0, [r7]
_081ECECC:
	subs r1, r1, r0
_081ECECE:
	strh r1, [r7, #2]
_081ECED0:
	movs r0, #1
	b _081ECEE8
_081ECED4:
	cmp r4, sb
	beq _081ECED0
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _081ECE28
_081ECEE6:
	movs r0, #0
_081ECEE8:
	cmp r0, #0
	beq _081ECEF2
	mov r1, sp
	movs r0, #1
	strb r0, [r1]
_081ECEF2:
	ldr r2, [sp, #0x4c]
	mov sb, r2
	ldrh r0, [r7, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x18
	mov sl, r0
	ldr r3, _081ECF4C @ =0x030046A4
	ldr r0, [r3]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	movs r3, #6
	ldrsh r0, [r0, r3]
	adds r2, r1, #0
	muls r2, r0, r2
	str r2, [sp, #0x40]
	ldr r3, [sp, #0x2c]
	cmp r3, sb
	blt _081ECF1A
	b _081ED0C2
_081ECF1A:
	ldr r4, [sp, #0x50]
	adds r0, r4, #0
	bl Mod
	adds r6, r0, #0
	ldr r1, _081ECF4C @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	bge _081ECFEC
	mov r8, r1
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081ECF3A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECF50
	adds r0, #4
	b _081ECF58
	.align 2, 0
_081ECF4C: .4byte 0x030046A4
_081ECF50:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECF58:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081ECFEC
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECF72
	adds r0, #4
	b _081ECF7A
_081ECF72:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECF7A:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ECFEC
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECF94
	adds r0, #4
	b _081ECF9C
_081ECF94:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECF9C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ECFD2
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ECFB4
	adds r0, #4
	b _081ECFBC
_081ECFB4:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ECFBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r2, r0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ECFCE
	b _081ED230
_081ECFCE:
	ldrb r0, [r7, #4]
	b _081ED23C
_081ECFD2:
	cmp r4, sb
	bne _081ECFD8
	b _081ED240
_081ECFD8:
	adds r5, #4
	adds r4, #1
	adds r6, #1
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	cmp r6, r0
	blt _081ECF3A
_081ECFEC:
	ldr r1, _081ED018 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r0, [r0, r3]
	ldr r2, [sp, #0x2c]
	adds r4, r2, r0
	ldr r3, [sp, #0x40]
	cmp r3, r4
	bgt _081ED002
	b _081ED256
_081ED002:
	adds r5, r1, #0
	movs r6, #0xf
_081ED006:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED01C
	adds r0, #4
	b _081ED026
	.align 2, 0
_081ED018: .4byte 0x030046A4
_081ED01C:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED026:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	beq _081ED032
	b _081ED256
_081ED032:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED042
	adds r0, #4
	b _081ED04C
_081ED042:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED04C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081ED058
	b _081ED256
_081ED058:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED068
	adds r0, #4
	b _081ED072
_081ED068:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED072:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081ED0AA
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED08A
	adds r0, #4
	b _081ED094
_081ED08A:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED094:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED0A6
	b _081ED230
_081ED0A6:
	ldrb r0, [r7, #4]
	b _081ED23C
_081ED0AA:
	cmp r4, sb
	bne _081ED0B0
	b _081ED240
_081ED0B0:
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r4, r4, r0
	ldr r2, [sp, #0x40]
	cmp r2, r4
	bgt _081ED006
	b _081ED256
_081ED0C2:
	mov r4, sb
	adds r0, r4, #0
	bl Mod
	adds r6, r0, #0
	cmp r6, #0
	blt _081ED180
	ldr r3, _081ED0EC @ =0x030046A4
	mov r8, r3
	lsls r0, r4, #2
	adds r5, r0, #0
	adds r5, #0xc
_081ED0DA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED0F0
	adds r0, #4
	b _081ED0F8
	.align 2, 0
_081ED0EC: .4byte 0x030046A4
_081ED0F0:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ED0F8:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, sl
	bne _081ED180
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED112
	adds r0, #4
	b _081ED11A
_081ED112:
	mov r2, r8
	ldr r0, [r2]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ED11A:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ED180
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED134
	adds r0, #4
	b _081ED13C
_081ED134:
	mov r3, r8
	ldr r0, [r3]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ED13C:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ED172
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED154
	adds r0, #4
	b _081ED15C
_081ED154:
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	adds r0, r0, r5
_081ED15C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r3, #0xf
	ands r2, r3
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	bne _081ED230
	ldrb r0, [r7, #4]
	b _081ED23C
_081ED172:
	cmp r4, sb
	beq _081ED240
	subs r5, #4
	subs r4, #1
	subs r6, #1
	cmp r6, #0
	bge _081ED0DA
_081ED180:
	ldr r1, _081ED1A8 @ =0x030046A4
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x2c]
	subs r4, r3, r0
	cmp r4, #0
	blt _081ED256
	adds r5, r1, #0
	movs r6, #0xf
_081ED196:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED1AC
	adds r0, #4
	b _081ED1B6
	.align 2, 0
_081ED1A8: .4byte 0x030046A4
_081ED1AC:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED1B6:
	ldrb r1, [r0]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, sl
	bne _081ED256
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED1D0
	adds r0, #4
	b _081ED1DA
_081ED1D0:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED1DA:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ED256
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED1F4
	adds r0, #4
	b _081ED1FE
_081ED1F4:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED1FE:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081ED244
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED216
	adds r0, #4
	b _081ED220
_081ED216:
	ldr r0, [r5]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081ED220:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	ands r2, r6
	adds r0, r6, #0
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED236
_081ED230:
	cmp r2, #2
	beq _081ED23A
	b _081ED23E
_081ED236:
	ldrb r0, [r7, #4]
	b _081ED23C
_081ED23A:
	ldrb r0, [r7]
_081ED23C:
	subs r1, r1, r0
_081ED23E:
	strh r1, [r7, #2]
_081ED240:
	movs r0, #1
	b _081ED258
_081ED244:
	cmp r4, sb
	beq _081ED240
	ldr r0, [r5]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	subs r4, r4, r0
	cmp r4, #0
	bge _081ED196
_081ED256:
	movs r0, #0
_081ED258:
	cmp r0, #0
	beq _081ED262
	mov r1, sp
	movs r0, #1
	strb r0, [r1, #2]
_081ED262:
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	cmp r0, #1
	bne _081ED272
	ldr r4, [sp, #0x30]
	b _081ED288
_081ED26E:
	adds r4, r1, #0
	b _081ED288
_081ED272:
	movs r1, #0
_081ED274:
	mov r3, sp
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081ED26E
	adds r1, #1
	cmp r1, #3
	ble _081ED274
	movs r4, #1
	rsbs r4, r4, #0
_081ED288:
	cmp r4, #0
	bge _081ED28E
	b _081ED62E
_081ED28E:
	ldr r5, [sp, #0xc]
	adds r5, #0x78
	movs r0, #0
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _081ED29C
	rsbs r1, r1, #0
_081ED29C:
	ldr r2, [sp, #0xc]
	adds r2, #0x7c
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bge _081ED2AA
	rsbs r0, r0, #0
_081ED2AA:
	adds r3, r0, #0
	cmp r3, r1
	bge _081ED2B2
	adds r3, r1, #0
_081ED2B2:
	cmp r4, #1
	beq _081ED2D0
	cmp r4, #1
	bgt _081ED2C0
	cmp r4, #0
	beq _081ED2CA
	b _081ED636
_081ED2C0:
	cmp r4, #2
	beq _081ED2D8
	cmp r4, #3
	beq _081ED2E2
	b _081ED636
_081ED2CA:
	strh r3, [r5]
	strh r4, [r2]
	b _081ED636
_081ED2D0:
	movs r0, #0
	strh r0, [r5]
	strh r3, [r2]
	b _081ED636
_081ED2D8:
	rsbs r0, r3, #0
	movs r1, #0
	strh r0, [r5]
	strh r1, [r2]
	b _081ED636
_081ED2E2:
	movs r0, #0
	strh r0, [r5]
	rsbs r0, r3, #0
	strh r0, [r2]
	b _081ED636

	thumb_func_start FUN_081ed2ec
FUN_081ed2ec: @ 0x081ED2EC
	ldr r0, [sp, #0xc]
	adds r0, #0xd4
	ldrh r4, [r0]
	ldr r6, [sp, #0xc]
	adds r6, #0x70
	adds r0, r1, #0
	adds r0, #0x20
	asrs r1, r0, #6
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	beq _081ED3E8
	cmp r1, #1
	bgt _081ED30E
	cmp r1, #0
	beq _081ED31C
	b _081ED628
_081ED30E:
	cmp r1, #2
	bne _081ED314
	b _081ED4AE
_081ED314:
	cmp r1, #3
	bne _081ED31A
	b _081ED564
_081ED31A:
	b _081ED628
_081ED31C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED32C
	adds r0, #4
	b _081ED338
_081ED32C:
	ldr r0, _081ED354 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED338:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ED342
	b _081ED624
_081ED342:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED358
	adds r0, #4
	b _081ED364
	.align 2, 0
_081ED354: .4byte 0x030046A4
_081ED358:
	ldr r0, _081ED380 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED364:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ED36E
	b _081ED624
_081ED36E:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED384
	adds r0, #4
	b _081ED390
	.align 2, 0
_081ED380: .4byte 0x030046A4
_081ED384:
	ldr r0, _081ED3AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED390:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081ED39C
	b _081ED628
_081ED39C:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED3B0
	adds r0, #4
	b _081ED3BC
	.align 2, 0
_081ED3AC: .4byte 0x030046A4
_081ED3B0:
	ldr r0, _081ED3D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED3BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED3D4
_081ED3CA:
	cmp r2, #2
	beq _081ED3D8
	b _081ED3DC
	.align 2, 0
_081ED3D0: .4byte 0x030046A4
_081ED3D4:
	ldrb r0, [r6, #4]
	b _081ED3DA
_081ED3D8:
	ldrb r0, [r6]
_081ED3DA:
	subs r1, r1, r0
_081ED3DC:
	movs r2, #2
	ldrsh r0, [r6, r2]
_081ED3E0:
	cmp r1, r0
	bne _081ED3E6
	b _081ED624
_081ED3E6:
	b _081ED628
_081ED3E8:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED3F8
	adds r0, #4
	b _081ED404
_081ED3F8:
	ldr r0, _081ED420 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED404:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081ED40E
	b _081ED624
_081ED40E:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED424
	adds r0, #4
	b _081ED430
	.align 2, 0
_081ED420: .4byte 0x030046A4
_081ED424:
	ldr r0, _081ED44C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED430:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	bne _081ED43A
	b _081ED624
_081ED43A:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED450
	adds r0, #4
	b _081ED45C
	.align 2, 0
_081ED44C: .4byte 0x030046A4
_081ED450:
	ldr r0, _081ED478 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED45C:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081ED468
	b _081ED628
_081ED468:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED47C
	adds r0, #4
	b _081ED488
	.align 2, 0
_081ED478: .4byte 0x030046A4
_081ED47C:
	ldr r0, _081ED49C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED488:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED4A0
	cmp r2, #2
	beq _081ED4A4
	b _081ED4A8
	.align 2, 0
_081ED49C: .4byte 0x030046A4
_081ED4A0:
	ldrb r0, [r6, #4]
	b _081ED4A6
_081ED4A4:
	ldrb r0, [r6]
_081ED4A6:
	subs r1, r1, r0
_081ED4A8:
	movs r3, #2
	ldrsh r0, [r6, r3]
	b _081ED3E0
_081ED4AE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED4BE
	adds r0, #4
	b _081ED4CA
_081ED4BE:
	ldr r0, _081ED4E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED4CA:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ED4D4
	b _081ED624
_081ED4D4:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED4E8
	adds r0, #4
	b _081ED4F4
	.align 2, 0
_081ED4E4: .4byte 0x030046A4
_081ED4E8:
	ldr r0, _081ED510 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED4F4:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #2
	bne _081ED4FE
	b _081ED624
_081ED4FE:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED514
	adds r0, #4
	b _081ED520
	.align 2, 0
_081ED510: .4byte 0x030046A4
_081ED514:
	ldr r0, _081ED53C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED520:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	beq _081ED52C
	b _081ED628
_081ED52C:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED540
	adds r0, #4
	b _081ED54C
	.align 2, 0
_081ED53C: .4byte 0x030046A4
_081ED540:
	ldr r0, _081ED560 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED54C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED55C
	b _081ED3CA
_081ED55C:
	ldrb r0, [r6, #4]
	b _081ED3DA
	.align 2, 0
_081ED560: .4byte 0x030046A4
_081ED564:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED574
	adds r0, #4
	b _081ED580
_081ED574:
	ldr r0, _081ED598 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED580:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	beq _081ED624
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED59C
	adds r0, #4
	b _081ED5A8
	.align 2, 0
_081ED598: .4byte 0x030046A4
_081ED59C:
	ldr r0, _081ED5C0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED5A8:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #1
	beq _081ED624
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED5C4
	adds r0, #4
	b _081ED5D0
	.align 2, 0
_081ED5C0: .4byte 0x030046A4
_081ED5C4:
	ldr r0, _081ED5EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED5D0:
	ldrh r0, [r0, #2]
	movs r1, #0xc3
	ands r0, r1
	cmp r0, #0
	bne _081ED628
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED5F0
	adds r0, #4
	b _081ED5FC
	.align 2, 0
_081ED5EC: .4byte 0x030046A4
_081ED5F0:
	ldr r0, _081ED610 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED5FC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED614
	cmp r2, #2
	beq _081ED618
	b _081ED61C
	.align 2, 0
_081ED610: .4byte 0x030046A4
_081ED614:
	ldrb r0, [r6, #4]
	b _081ED61A
_081ED618:
	ldrb r0, [r6]
_081ED61A:
	subs r1, r1, r0
_081ED61C:
	movs r3, #2
	ldrsh r0, [r6, r3]
	cmp r1, r0
	bne _081ED628
_081ED624:
	movs r0, #1
	b _081ED62A
_081ED628:
	movs r0, #0
_081ED62A:
	cmp r0, #0
	bne _081ED63A
_081ED62E:
	ldr r1, [sp, #0xc]
	adds r1, #0xd7
	movs r0, #2
	strb r0, [r1]
_081ED636:
	movs r0, #1
	b _081ED63C
_081ED63A:
	movs r0, #0
_081ED63C:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081ed64c
FUN_081ed64c: @ 0x081ED64C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ed650
FUN_081ed650: @ 0x081ED650
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r2, #0
	mov r4, sp
	ldrh r0, [r1]
	ldrh r2, [r5]
	subs r0, r0, r2
	mov r2, sp
	strh r0, [r2]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	subs r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r1, r2, #0
	muls r1, r2, r1
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _081ED6C8 @ =0x000003FF
	cmp r1, r0
	ble _081ED6C2
	adds r0, r2, #0
	movs r1, #2
	bl Div
	ldrh r1, [r5]
	adds r1, r1, r0
	mov r0, sp
	strh r1, [r0]
	ldrh r0, [r5, #2]
	strh r0, [r4, #2]
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r1, #2
	bl Div
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r1, #2
	adds r2, r6, #0
	bl FUN_081eb178
	cmp r0, #0
	blt _081ED6CC
_081ED6C2:
	movs r0, #1
	b _081ED6CE
	.align 2, 0
_081ED6C8: .4byte 0x000003FF
_081ED6CC:
	movs r0, #0
_081ED6CE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081ed6d8
FUN_081ed6d8: @ 0x081ED6D8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ed6dc
FUN_081ed6dc: @ 0x081ED6DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r1, #0
	adds r1, #0xd3
	ldrb r0, [r1]
	cmp r0, #0
	beq _081ED6F6
	movs r0, #0
	strb r0, [r1]
_081ED6F6:
	adds r0, r7, #0
	adds r0, #0xd8
	ldrh r1, [r0]
	str r0, [sp, #0x1c]
	cmp r1, #0
	beq _081ED70A
	subs r0, r1, #1
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
	b _081EDA44
_081ED70A:
	adds r0, r7, #0
	adds r0, #0x70
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov r8, r0
	cmp r2, #0
	blt _081ED734
	cmp r1, #0
	blt _081ED734
	ldr r0, _081ED738 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081ED734
	ldr r0, _081ED73C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081ED740
_081ED734:
	movs r0, #0
	b _081ED74E
	.align 2, 0
_081ED738: .4byte 0x030046A8
_081ED73C: .4byte 0x030046AC
_081ED740:
	ldr r0, _081ED794 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081ED74E:
	adds r5, r7, #0
	adds r5, #0xd4
	strh r0, [r5]
	adds r4, r7, #0
	adds r4, #0x78
	movs r2, #0
	ldrsh r0, [r4, r2]
	adds r6, r7, #0
	adds r6, #0x7c
	movs r3, #0
	ldrsh r1, [r6, r3]
	bl ArcTan2_8
	mov sl, r0
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x74]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldrh r0, [r4]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	ldrh r4, [r5]
	mov r5, r8
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED798
	adds r0, #4
	b _081ED7A4
	.align 2, 0
_081ED794: .4byte 0x030046A4
_081ED798:
	ldr r0, _081ED7B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED7A4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED7BC
	cmp r2, #2
	beq _081ED7C0
	b _081ED7C4
	.align 2, 0
_081ED7B8: .4byte 0x030046A4
_081ED7BC:
	ldrb r0, [r5, #4]
	b _081ED7C2
_081ED7C0:
	ldrb r0, [r5]
_081ED7C2:
	subs r1, r1, r0
_081ED7C4:
	adds r2, r7, #0
	adds r2, #0x72
	strh r1, [r2]
	adds r1, r7, #0
	adds r1, #0x74
	ldrh r0, [r6]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	mov r3, r8
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	adds r6, r2, #0
	mov sb, r1
	cmp r4, #0
	blt _081ED800
	cmp r3, #0
	blt _081ED800
	ldr r0, _081ED804 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081ED800
	ldr r0, _081ED808 @ =0x030046AC
	ldr r0, [r0]
	cmp r3, r0
	blo _081ED80C
_081ED800:
	movs r5, #0
	b _081ED81A
	.align 2, 0
_081ED804: .4byte 0x030046A8
_081ED808: .4byte 0x030046AC
_081ED80C:
	ldr r0, _081ED848 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r3, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r4
_081ED81A:
	adds r4, r7, #0
	adds r4, #0x80
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r0, r7, #0
	mov r1, sl
	adds r2, r5, #0
	bl FUN_081eb348
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081ED84C
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [r7, #0x70]
	str r1, [r7, #0x74]
	b _081ED88E
	.align 2, 0
_081ED848: .4byte 0x030046A4
_081ED84C:
	mov r4, r8
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081ED85E
	adds r0, #4
	b _081ED86A
_081ED85E:
	ldr r0, _081ED880 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081ED86A:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081ED884
	cmp r2, #2
	beq _081ED888
	b _081ED88C
	.align 2, 0
_081ED880: .4byte 0x030046A4
_081ED884:
	ldrb r0, [r4, #4]
	b _081ED88A
_081ED888:
	ldrb r0, [r4]
_081ED88A:
	subs r1, r1, r0
_081ED88C:
	strh r1, [r6]
_081ED88E:
	ldr r0, [r7, #0x70]
	ldr r1, [r7, #0x74]
	str r0, [r7, #8]
	str r1, [r7, #0xc]
	ldr r2, _081ED8C4 @ =0xFFFF0000
	ldrh r1, [r6]
	lsls r1, r1, #0x10
	mov r3, r8
	ldrh r0, [r3]
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sb
	ldrh r1, [r0]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	mov r1, sl
	asrs r0, r1, #6
	cmp r0, #1
	beq _081ED914
	cmp r0, #1
	bgt _081ED8C8
	cmp r0, #0
	beq _081ED8D2
	b _081ED944
	.align 2, 0
_081ED8C4: .4byte 0xFFFF0000
_081ED8C8:
	cmp r0, #2
	beq _081ED8D2
	cmp r0, #3
	beq _081ED914
	b _081ED944
_081ED8D2:
	ldr r2, _081ED904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081ED908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081ED90C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x78
	bl Mod
	add r1, sp, #0xc
	ldrh r1, [r1, #4]
	subs r1, #0x3c
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081ED910 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	b _081ED944
	.align 2, 0
_081ED904: .4byte 0x030046B8
_081ED908: .4byte 0x000003FF
_081ED90C: .4byte 0x0203B400
_081ED910: .4byte 0xFFFF0000
_081ED914:
	ldr r2, _081ED9BC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081ED9C0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _081ED9C4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x78
	bl Mod
	add r1, sp, #0xc
	ldrh r1, [r1]
	subs r1, #0x3c
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081ED9C8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
_081ED944:
	adds r0, r7, #0
	adds r0, #0xd2
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #2
	bne _081ED9CC
	movs r5, #0
	movs r0, #0xd0
	adds r0, r0, r7
	mov sb, r0
_081ED958:
	lsls r3, r5, #6
	movs r0, #0x54
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	add r0, sp, #0xc
	movs r1, #1
	movs r2, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #3
	ble _081ED958
	movs r5, #0
	movs r1, #1
	mov r8, r1
	movs r6, #0
_081ED97E:
	lsls r4, r5, #6
	movs r0, #0x22
	str r0, [sp]
	mov r2, r8
	str r2, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0xc
	movs r1, #1
	movs r2, #8
	adds r3, r4, #0
	bl FUN_081eec74
	movs r0, #0x40
	str r0, [sp]
	mov r3, r8
	str r3, [sp, #4]
	str r6, [sp, #8]
	add r0, sp, #0xc
	movs r1, #1
	movs r2, #0xe
	adds r3, r4, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #1
	ble _081ED97E
	movs r0, #8
	ldr r1, [sp, #0x1c]
	strh r0, [r1]
	b _081EDA12
	.align 2, 0
_081ED9BC: .4byte 0x030046B8
_081ED9C0: .4byte 0x000003FF
_081ED9C4: .4byte 0x0203B400
_081ED9C8: .4byte 0xFFFF0000
_081ED9CC:
	mov r3, sl
	ldrb r2, [r3]
	add r0, sp, #0xc
	movs r1, #2
	bl FUN_081eb178
	cmp r0, #0
	blt _081EDA3C
	add r0, sp, #0x14
	mov r1, sl
	ldrb r2, [r1]
	add r1, sp, #0xc
	bl FUN_081ed650
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081EDA3C
	ldr r2, _081EDA30 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081EDA34 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081EDA38 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #3
	ldr r3, [sp, #0x1c]
	strh r0, [r3]
	movs r0, #0xd0
	adds r0, r0, r7
	mov sb, r0
_081EDA12:
	mov r1, sb
	ldrh r0, [r1]
	cmp r0, #0
	beq _081EDA3C
	subs r0, #1
	strh r0, [r1]
	mov r2, sl
	ldrb r0, [r2]
	cmp r0, #2
	beq _081EDA44
	movs r0, #0xf1
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081EDA44
	.align 2, 0
_081EDA30: .4byte 0x030046B8
_081EDA34: .4byte 0x000003FF
_081EDA38: .4byte 0x0203B400
_081EDA3C:
	adds r1, r7, #0
	adds r1, #0xd7
	movs r0, #2
	strb r0, [r1]
_081EDA44:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081eda54
FUN_081eda54: @ 0x081EDA54
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r2, r4, #0
	adds r2, #0xd7
	movs r1, #0
	strb r1, [r2]
	adds r5, r4, #0
	adds r5, #0xd6
	movs r1, #0
	ldrsb r1, [r5, r1]
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r0, r2
	movs r2, #1
	lsls r2, r1
	ldr r1, [r0]
	bics r1, r2
	str r1, [r0]
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl Mover_Unlink
	adds r0, r4, #0
	movs r1, #0xdc
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081eda98
FUN_081eda98: @ 0x081EDA98
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r5, #1
_081EDAA6:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081EDAB6
	movs r0, #1
	b _081EDAB8
_081EDAB6:
	movs r0, #0
_081EDAB8:
	cmp r0, #0
	bne _081EDAD6
	movs r0, #0xdc
	muls r0, r3, r0
	adds r0, #0x18
	adds r0, r2, r0
	adds r1, r0, #0
	adds r1, #0xd6
	strb r3, [r1]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _081EDADE
_081EDAD6:
	adds r3, #1
	cmp r3, #1
	ble _081EDAA6
	movs r0, #0
_081EDADE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081edae4
FUN_081edae4: @ 0x081EDAE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	cmp r4, #0
	beq _081EDB14
	ldr r0, _081EDB1C @ =0x030001C8
	ldr r0, [r0]
	cmp r0, #0
	bne _081EDB0A
	bl Entity081edcc4_Create
	cmp r0, #0
	beq _081EDB14
_081EDB0A:
	bl FUN_081eda98
	adds r5, r0, #0
	cmp r5, #0
	bne _081EDB20
_081EDB14:
	movs r0, #1
	rsbs r0, r0, #0
	b _081EDC32
	.align 2, 0
_081EDB1C: .4byte 0x030001C8
_081EDB20:
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r5, #0x70]
	str r1, [r5, #0x74]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x78]
	str r1, [r5, #0x7c]
	adds r0, r5, #0
	adds r0, #0xd0
	movs r7, #0
	mov r1, r8
	strh r1, [r0]
	adds r4, r5, #0
	adds r4, #0xd2
	mov r0, sb
	strb r0, [r4]
	adds r0, r5, #0
	adds r0, #0xd8
	strh r7, [r0]
	adds r1, r5, #0
	adds r1, #0xd7
	movs r0, #1
	strb r0, [r1]
	adds r6, r5, #0
	adds r6, #0x80
	ldr r2, _081EDBAC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _081EDBB0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldrb r0, [r4]
	cmp r0, #2
	bne _081EDBBC
	str r7, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	ldr r2, _081EDBB4 @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	ldr r0, _081EDBB8 @ =0x00240004
	str r0, [sp]
	ldr r1, [sp, #0x40]
	str r1, [sp, #4]
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	movs r3, #0x40
	bl Hitbox_SetAttack
	b _081EDBE4
	.align 2, 0
_081EDBAC: .4byte 0xFFFF0000
_081EDBB0: .4byte 0x0000FFFF
_081EDBB4: .4byte 0x00002001
_081EDBB8: .4byte 0x00240004
_081EDBBC:
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	ldr r2, _081EDC40 @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	str r7, [sp]
	ldr r1, [sp, #0x40]
	str r1, [sp, #4]
	adds r0, r6, #0
	ldr r1, [sp, #0x38]
	ldr r2, [sp, #0x3c]
	movs r3, #0x10
	bl Hitbox_SetAttack
_081EDBE4:
	ldrh r0, [r5]
	strh r0, [r6, #4]
	adds r4, r5, #0
	adds r4, #0x70
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081EDC44 @ =FUN_081ed64c
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r5, #0
	adds r0, #0xd6
	movs r1, #0
	ldrsb r1, [r0, r1]
	ldr r0, _081EDC48 @ =0x00000309
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r5, #0
	adds r2, r4, #0
	movs r3, #0
	bl Mover_Init
	adds r1, r5, #0
	adds r1, #0x44
	adds r0, r5, #0
	bl Mover_SetAuxSprite
	adds r0, r5, #0
	bl FUN_08002a48
	movs r0, #0
_081EDC32:
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EDC40: .4byte 0x00002001
_081EDC44: .4byte FUN_081ed64c
_081EDC48: .4byte 0x00000309

	thumb_func_start Entity081edcc4_Update
Entity081edcc4_Update: @ 0x081EDC4C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EDCA4
	movs r4, #0
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r7, _081EDC78 @ =0x085AE4BC
_081EDC66:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EDC7C
	movs r0, #1
	b _081EDC7E
	.align 2, 0
_081EDC78: .4byte 0x085AE4BC
_081EDC7C:
	movs r0, #0
_081EDC7E:
	cmp r0, #0
	beq _081EDC9E
	movs r0, #0xdc
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, #0x18
	adds r1, r5, r1
	adds r0, r1, #0
	adds r0, #0xd7
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EDC9E:
	adds r4, #1
	cmp r4, #1
	ble _081EDC66
_081EDCA4:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081edcc4_Destroy
Entity081edcc4_Destroy: @ 0x081EDCAC
	ldr r1, _081EDCB4 @ =0x030001C8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EDCB4: .4byte 0x030001C8

	thumb_func_start Entity081edcc4_Init
Entity081edcc4_Init: @ 0x081EDCB8
	ldr r1, _081EDCC0 @ =0x030001C8
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081EDCC0: .4byte 0x030001C8

	thumb_func_start Entity081edcc4_Create
Entity081edcc4_Create: @ 0x081EDCC4
	push {r4, lr}
	ldr r0, _081EDCFC @ =0x030001C8
	ldr r0, [r0]
	cmp r0, #0
	bne _081EDD0A
	movs r1, #0xea
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EDD08
	ldr r1, _081EDD00 @ =Entity081edcc4_Update
	ldr r2, _081EDD04 @ =Entity081edcc4_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081edcc4_Init
	cmp r0, #0
	bge _081EDD08
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EDD0A
	.align 2, 0
_081EDCFC: .4byte 0x030001C8
_081EDD00: .4byte Entity081edcc4_Update
_081EDD04: .4byte Entity081edcc4_Destroy
_081EDD08:
	adds r0, r4, #0
_081EDD0A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081edd10
FUN_081edd10: @ 0x081EDD10
	ldr r1, _081EDD18 @ =0x030001C8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EDD18: .4byte 0x030001C8
